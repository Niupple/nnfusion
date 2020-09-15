// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

/**
 * \brief Unit tests for program::Min
 * \author generated by script
 */

#include "../test_util/common.hpp"

namespace nnfusion
{
    namespace test
    {
        template <typename T, size_t N>
        using NDArray = nnfusion::test::NDArray<T, N>;
    }

    namespace inventory
    {
        template <>
        shared_ptr<graph::GNode> create_object<op::Min, float>(int option)
        {
            switch (option)
            {
            case 0:
            {
                auto graph = std::make_shared<graph::Graph>();
                Shape shape{2, 2};
                auto A = make_shared<op::Parameter>(element::f32, shape);
                auto A_gnode = graph->add_node_and_edge(A, GNodeVector({}));
                auto r = make_shared<op::Min>(AxisSet{});
                auto r_gnode = graph->add_node_and_edge(r, {A_gnode});
                return r_gnode;
            }
            case 1:
            {
                auto graph = std::make_shared<graph::Graph>();
                Shape shape{2, 2, 2, 2, 2};
                auto A = make_shared<op::Parameter>(element::f32, shape);
                auto A_gnode = graph->add_node_and_edge(A, GNodeVector({}));
                auto r = make_shared<op::Min>(AxisSet{});
                auto r_gnode = graph->add_node_and_edge(r, {A_gnode});
                return r_gnode;
            }
            case 2:
            {
                auto graph = std::make_shared<graph::Graph>();
                Shape shape{2, 2};
                auto A = make_shared<op::Parameter>(element::f32, shape);
                auto A_gnode = graph->add_node_and_edge(A, GNodeVector({}));
                auto r = make_shared<op::Min>(AxisSet{0, 1});
                auto r_gnode = graph->add_node_and_edge(r, {A_gnode});
                return r_gnode;
            }
            case 3:
            {
                auto graph = std::make_shared<graph::Graph>();
                Shape shape_a{3, 2};
                auto A = make_shared<op::Parameter>(element::f32, shape_a);
                auto A_gnode = graph->add_node_and_edge(A, GNodeVector({}));
                auto r = make_shared<op::Min>(AxisSet{0});
                auto r_gnode = graph->add_node_and_edge(r, {A_gnode});
                return r_gnode;
            }
            case 4:
            {
                auto graph = std::make_shared<graph::Graph>();
                Shape shape_a{3, 2};
                auto A = make_shared<op::Parameter>(element::f32, shape_a);
                auto A_gnode = graph->add_node_and_edge(A, GNodeVector({}));
                auto r = make_shared<op::Min>(AxisSet{1});
                auto r_gnode = graph->add_node_and_edge(r, {A_gnode});
                return r_gnode;
            }
            case 5:
            {
                auto graph = std::make_shared<graph::Graph>();
                Shape shape_a{3, 3, 3};
                auto A = make_shared<op::Parameter>(element::f32, shape_a);
                auto A_gnode = graph->add_node_and_edge(A, GNodeVector({}));
                auto r = make_shared<op::Min>(AxisSet{0});
                auto r_gnode = graph->add_node_and_edge(r, {A_gnode});
                return r_gnode;
            }
            case 6:
            {
                auto graph = std::make_shared<graph::Graph>();
                Shape shape_a{3, 3, 3};
                auto A = make_shared<op::Parameter>(element::f32, shape_a);
                auto A_gnode = graph->add_node_and_edge(A, GNodeVector({}));
                auto r = make_shared<op::Min>(AxisSet{2});
                auto r_gnode = graph->add_node_and_edge(r, {A_gnode});
                return r_gnode;
            }
            case 7:
            {
                auto graph = std::make_shared<graph::Graph>();
                Shape shape_a{3, 3, 3};
                auto A = make_shared<op::Parameter>(element::f32, shape_a);
                auto A_gnode = graph->add_node_and_edge(A, GNodeVector({}));
                auto r = make_shared<op::Min>(AxisSet{0, 1});
                auto r_gnode = graph->add_node_and_edge(r, {A_gnode});
                return r_gnode;
            }
            case 8:
            {
                auto graph = std::make_shared<graph::Graph>();
                Shape shape_a{3, 3, 3};
                auto A = make_shared<op::Parameter>(element::f32, shape_a);
                auto A_gnode = graph->add_node_and_edge(A, GNodeVector({}));
                auto r = make_shared<op::Min>(AxisSet{0, 1, 2});
                auto r_gnode = graph->add_node_and_edge(r, {A_gnode});
                return r_gnode;
            }
            default: return nullptr;
            }
        }

        template <>
        vector<float> generate_input<op::Min, float>(int option)
        {
            switch (option)
            {
            case 0:
            {
                vector<float> a = vector<float>{1, 2, 3, 4};
                auto return_vector = vector<float>();
                return_vector.insert(return_vector.end(), a.begin(), a.end());
                return return_vector;
            }
            case 1:
            {
                vector<float> a = vector<float>{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
                auto return_vector = vector<float>();
                return_vector.insert(return_vector.end(), a.begin(), a.end());
                return return_vector;
            }
            case 2:
            {
                vector<float> a = vector<float>{1, 2, 3, 4};
                auto return_vector = vector<float>();
                return_vector.insert(return_vector.end(), a.begin(), a.end());
                return return_vector;
            }
            case 3:
            {
                vector<float> a = vector<float>{1, 2, 3, 4, 5, 6};
                auto return_vector = vector<float>();
                return_vector.insert(return_vector.end(), a.begin(), a.end());
                return return_vector;
            }
            case 4:
            {
                vector<float> a = vector<float>{1, 2, 3, 4, 5, 6};
                auto return_vector = vector<float>();
                return_vector.insert(return_vector.end(), a.begin(), a.end());
                return return_vector;
            }
            case 5:
            {
                vector<float> a =
                    vector<float>{1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14,
                                  15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27};
                auto return_vector = vector<float>();
                return_vector.insert(return_vector.end(), a.begin(), a.end());
                return return_vector;
            }
            case 6:
            {
                vector<float> a =
                    vector<float>{1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14,
                                  15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27};
                auto return_vector = vector<float>();
                return_vector.insert(return_vector.end(), a.begin(), a.end());
                return return_vector;
            }
            case 7:
            {
                vector<float> a =
                    vector<float>{1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14,
                                  15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27};
                auto return_vector = vector<float>();
                return_vector.insert(return_vector.end(), a.begin(), a.end());
                return return_vector;
            }
            case 8:
            {
                vector<float> a = vector<float>{1,  2,  3,  4,  5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
                                                13, 12, 11, 10, 9, 8, 7, 6, 5, 4,  3,  2,  1};
                auto return_vector = vector<float>();
                return_vector.insert(return_vector.end(), a.begin(), a.end());
                return return_vector;
            }
            default: return vector<float>();
            }
        }

        template <>
        vector<float> generate_output<op::Min, float>(int option)
        {
            switch (option)
            {
            case 0:
            {
                vector<float> result = vector<float>{1, 2, 3, 4};
                auto return_vector = vector<float>();
                return_vector.insert(return_vector.end(), result.begin(), result.end());
                return return_vector;
            }
            case 1:
            {
                vector<float> result =
                    vector<float>{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
                auto return_vector = vector<float>();
                return_vector.insert(return_vector.end(), result.begin(), result.end());
                return return_vector;
            }
            case 2:
            {
                vector<float> result = vector<float>{1};
                auto return_vector = vector<float>();
                return_vector.insert(return_vector.end(), result.begin(), result.end());
                return return_vector;
            }
            case 3:
            {
                vector<float> result = vector<float>{1, 2};
                auto return_vector = vector<float>();
                return_vector.insert(return_vector.end(), result.begin(), result.end());
                return return_vector;
            }
            case 4:
            {
                vector<float> result = vector<float>{1, 3, 5};
                auto return_vector = vector<float>();
                return_vector.insert(return_vector.end(), result.begin(), result.end());
                return return_vector;
            }
            case 5:
            {
                vector<float> result = vector<float>{1, 2, 3, 4, 5, 6, 7, 8, 9};
                auto return_vector = vector<float>();
                return_vector.insert(return_vector.end(), result.begin(), result.end());
                return return_vector;
            }
            case 6:
            {
                vector<float> result = vector<float>{1, 4, 7, 10, 13, 16, 19, 22, 25};
                auto return_vector = vector<float>();
                return_vector.insert(return_vector.end(), result.begin(), result.end());
                return return_vector;
            }
            case 7:
            {
                vector<float> result = vector<float>{1, 2, 3};
                auto return_vector = vector<float>();
                return_vector.insert(return_vector.end(), result.begin(), result.end());
                return return_vector;
            }
            case 8:
            {
                vector<float> result = vector<float>{1};
                auto return_vector = vector<float>();
                return_vector.insert(return_vector.end(), result.begin(), result.end());
                return return_vector;
            }
            default: return vector<float>();
            }
        }
    }
}