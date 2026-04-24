/** 
 * Copyright (c) 2016 SQLines
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef sqlines_license_h
#define sqlines_license_h

#include <string>

class License
{
private:
    std::string _name;

public:
    License() {}

    void Set(const char* app) { _name = app ? app : ""; }
    std::string GetName() { return _name; }
    bool IsLicenseCheckRequired() { return false; }
    bool IsEmpty() { return true; }
};

#endif // sqlines_license_h
