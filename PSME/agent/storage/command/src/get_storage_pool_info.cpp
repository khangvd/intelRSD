/*!
 * @brief GetStoragePoolInfo command implementation.
 *
 * @copyright Copyright (c) 2017-2019 Intel Corporation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0.
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @file get_storage_pool_info.cpp
 */

#include "agent-framework/module/storage_components.hpp"
#include "storage_agent_commands.hpp"

using namespace agent::storage;
using namespace agent_framework::module;
using namespace agent_framework::model;

REGISTER_STORAGE_COMMAND(GetStoragePoolInfo,
    [] (GetStoragePoolInfo::ContextPtr,
        const GetStoragePoolInfo::Request& request,
        GetStoragePoolInfo::Response& response) {
        log_debug("storage-agent", "Getting storage pool info.");
        response = get_manager<StoragePool>().get_entry(request.get_uuid());
    }
);
