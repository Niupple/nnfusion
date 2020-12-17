// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#pragma once

#include "graph_pass_base.hpp"

namespace nnfusion
{
    namespace pass
    {
        namespace graph
        {
            class AutoMixedPrecision : GraphPassBase
            {
            public:
                bool run_on_graph(std::shared_ptr<nnfusion::graph::Graph>& graph) override;
            };

            class AmpPolicy
            {
            public:
                AmpPolicy();

                virtual bool cast(std::shared_ptr<Graph> &graph, std::shared_ptr<GNode> &node) const;
            };

            class PureHalfPolicy : public AmpPolicy
            {
            public:
                PureHalfPolicy();

                bool cast(std::shared_ptr<Graph> &graph, std::shared_ptr<GNode> &node) const override;
            };
        }   // namespace graph
    }   // namespace pass
}   // namespace nnfusion