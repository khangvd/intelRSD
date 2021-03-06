/*!
 * Copyright (c) 2015-2019 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @file requests/network/get_port_static_mac_info.cpp
 * @brief Network request get port static MAC information implementation
 * */

#include "agent-framework/module/requests/network/get_port_static_mac_info.hpp"
#include "agent-framework/module/constants/network.hpp"
#include "json-wrapper/json-wrapper.hpp"

using namespace agent_framework::model::requests;
using namespace agent_framework::model::literals;

GetPortStaticMacInfo::GetPortStaticMacInfo(const std::string& static_mac): m_static_mac(static_mac){}

json::Json GetPortStaticMacInfo::to_json() const {
    json::Json value = json::Json();
    value[StaticMac::STATIC_MAC] = m_static_mac;
    return value;
}

GetPortStaticMacInfo GetPortStaticMacInfo::from_json(const json::Json& json) {
    return GetPortStaticMacInfo{
        json[StaticMac::STATIC_MAC].get<std::string>()
    };
}
