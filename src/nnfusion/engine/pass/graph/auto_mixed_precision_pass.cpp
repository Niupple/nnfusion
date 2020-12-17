// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#include "auto_mixed_precision_pass.hpp"
#include "gnode_device_dispatcher.hpp"
#include "cast.hpp"

using namespace nnfusion::pass::graph;
using namespace nnfusion::graph;

DEFINE_bool(fforced_casting, false, "Forced Datatype Casting.");
DECLARE_string(fcasting_to);

using Node_p = std::shared_ptr<GNode>;
using Graph_p = std::shared_ptr<Graph>;
using Edge_p = std::shared_ptr<Edge>;

namespace
{
    bool const_op_cast(Node_p &ret, Node_p &old)
    {
        
    }
}   // namespace

bool AutoMixedPrecision::run_on_graph(Graph_p& graph)
{
    bool using_pass = FLAGS_fforced_casting;
    if (!using_pass)
        return true;

    for (auto &it : graph->get_nodes())
    {
        if (it->get_op_type() == "Const")
        {

        }
        else
        {

        }
    }
}

AmpPolicy::AmpPolicy() {}

bool AmpPolicy::cast(std::shared_ptr<Graph> &graph, std::shared_ptr<GNode> &node) const
{
    return true;
}

PureHalfPolicy::PureHalfPolicy() {}

// Cast the given node on the given graph under the PureHalfPolicy
bool PureHalfPolicy::cast(std::shared_ptr<Graph> &graph, std::shared_ptr<GNode> &node) const
{
    // Node_p new_node = std::make_shared<GNode>()

    // Storing the new input node list, some of which are replaced by casting nodes
    GNodeVector new_in_nodes;
    size_t indeg = node->get_inputs().size();
    // Storing the edges that needs to be inserted with a casting node
    std::vector<std::pair<Edge_p, Node_p>> edges_to_replace(indeg);
    std::vector<int> added_cast(indeg);   // records whether each in_node is tailed with a cast node

    // it is necessary not to modify the graph while traversing it
    for (auto &edge : node->get_in_edges())
    {
        Node_p pre = edge->get_src();
        int output = edge->get_src_output();
        element::Type in_type = node->get_input_element_type(output);
        Shape shape = node->get_input_shape(output);
        Node_p new_node;
        if (in_type != element::f16)    // then a casting node should be inserted
        {
            std::shared_ptr<op::Op> cast_op = std::make_shared<op::Cast>(shape, in_type, element::f16);
            new_node = std::make_shared<GNode>(cast_op, GNodeVector{pre});
            edges_to_replace.push_back({edge, new_node});
            added_cast.push_back(1);
        }
        else
        {
            new_node = pre;
            edges_to_replace.push_back({edge, pre});
            added_cast.push_back(0);
        }
        new_in_nodes.push_back(new_node);
    }

    Node_p casted_node = std::make_shared<GNode>(node->get_op_ptr(), new_in_nodes);

    size_t i = 0;
    for (auto &pair : edges_to_replace)
    {
        int flag = added_cast.at(i++);
        Edge_p edge = pair.first;
        Node_p new_node = pair.second;
        Node_p src = edge->get_src();
        Node_p dst = edge->get_dst();
        int src_out = edge->get_src_output();
        int dst_in = edge->get_dst_input();
        // then modify the graph
        graph->remove_edge(edge);
        if (flag == 0)
        {
            graph->add_edge(src, src_out, casted_node, i);
        }
        else
        {
            graph->add_edge(src, src_out, new_node, 0);
            graph->add_edge(new_node, 0, casted_node, i);
        }
    }
}