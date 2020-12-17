// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#include "nnfusion/core/operators/generic_op/generic_op.hpp"

REGISTER_OP(Cast)
    .infershape(nnfusion::op::infershape::unimplemented_and_not_used)
    .translate([](std::shared_ptr<graph::GNode> gnode) -> std::string {
        

    })
    .translate_v2([](std::shared_ptr<graph::GNode> curr) -> std::string {
        
    });
