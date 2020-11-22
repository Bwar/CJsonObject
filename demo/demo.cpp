#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../CJsonObject.hpp"

//int main()
int main(int argc, char* argv[])
{
    std::ifstream fin(argv[1]);
    if (fin.good())
    {
        neb::CJsonObject oJson;
        std::stringstream ssContent;
        ssContent << fin.rdbuf();
        if (oJson.Parse(ssContent.str()))
        {
            std::cout << oJson.ToString() << std::endl;
        }
        else
        {
            std::cerr << "parse json error" << "\n";// << ssContent.str() << std::endl;
        }
        fin.close();
    }
    int iValue;
    double fTimeout;
    std::string strValue;
    neb::CJsonObject oJson("{\"refresh_interval\":60,"
                        "\"test_float\":[18.0, 10.0, 5.0],"
                        "\"test_int\":[135355, -1844674407370955161, -935375],"
                        "\"timeout\":12.5,"
                        "\"dynamic_loading\":["
                            "{"
                                "\"so_path\":\"plugins/User.so\", \"load\":false, \"version\":1,"
                                "\"cmd\":["
                                     "{\"cmd\":2001, \"class\":\"neb::CmdUserLogin\"},"
                                     "{\"cmd\":2003, \"class\":\"neb::CmdUserLogout\"}"
                                "],"
                                "\"module\":["
                                     "{\"path\":\"im/user/login\", \"class\":\"neb::ModuleLogin\"},"
                                     "{\"path\":\"im/user/logout\", \"class\":\"neb::ModuleLogout\"}"
                                "]"
                             "},"
                             "{"
                             "\"so_path\":\"plugins/ChatMsg.so\", \"load\":false, \"version\":1,"
                                 "\"cmd\":["
                                      "{\"cmd\":2001, \"class\":\"neb::CmdChat\"}"
                                 "],"
                             "\"module\":[]"
                             "}"
                        "]"
                    "}");
     std::cout << oJson.ToString() << std::endl;
     std::cout << "-------------------------------------------------------------------" << std::endl;
     std::cout << oJson["dynamic_loading"][0]["cmd"][1]("class") << std::endl;
     oJson["dynamic_loading"][0]["cmd"][0].Get("cmd", iValue);
     std::cout << "iValue = " << iValue << std::endl;
     oJson["dynamic_loading"][0]["cmd"][0].Replace("cmd", -2001);
     oJson["dynamic_loading"][0]["cmd"][0].Get("cmd", iValue);
     std::cout << "iValue = " << iValue << std::endl;
     oJson.Get("timeout", fTimeout);
     std::cout << "fTimeout = " << fTimeout << std::endl;
     oJson["dynamic_loading"][0]["module"][0].Get("path", strValue);
     std::cout << "strValue = " << strValue << std::endl;
     std::cout << "-------------------------------------------------------------------" << std::endl;
     oJson.AddEmptySubObject("depend");
     oJson["depend"].Add("nebula", "https://github.com/Bwar/Nebula");
     oJson["depend"].AddEmptySubArray("bootstrap");
     oJson["depend"]["bootstrap"].Add("BEACON");
     oJson["depend"]["bootstrap"].Add("LOGIC");
     oJson["depend"]["bootstrap"].Add("LOGGER");
     oJson["depend"]["bootstrap"].Add("INTERFACE");
     oJson["depend"]["bootstrap"].Add("ACCESS");
     std::cout << oJson.ToString() << std::endl;
     std::cout << "-------------------------------------------------------------------" << std::endl;
     std::cout << oJson.ToFormattedString() << std::endl;

     std::cout << "-------------------------------------------------------------------" << std::endl;
     neb::CJsonObject oCopyJson = oJson;
     if (oCopyJson == oJson)
     {
         std::cout << "json equal" << std::endl;
     }
     oCopyJson["depend"]["bootstrap"].Delete(1);
     oCopyJson["depend"].Replace("nebula", "https://github.com/Bwar/CJsonObject");
     std::cout << oCopyJson.ToString() << std::endl;
     std::cout << "-------------------------key traverse------------------------------" << std::endl;
     std::string strTraversing;
     while(oJson["dynamic_loading"][0].GetKey(strTraversing))
     {
         std::cout << "traversing:  " << strTraversing << std::endl;
     }
     std::cout << "---------------add a new key, then key traverse---------------------" << std::endl;
     oJson["dynamic_loading"][0].Add("new_key", "new_value");
     while(oJson["dynamic_loading"][0].GetKey(strTraversing))
     {
         std::cout << "traversing:  " << strTraversing << std::endl;
     }

     std::cout << oJson["test_float"].GetArraySize() << std::endl;
     float fTestValue = 0.0;
     for (int i = 0; i < oJson["test_float"].GetArraySize(); ++i)
     {
         oJson["test_float"].Get(i, fTestValue);
         std::cout << fTestValue << "\t in string: " << oJson["test_float"](i) << std::endl;
     }
     for (int i = 0; i < oJson["test_int"].GetArraySize(); ++i)
     {
         std::cout << "in string: " << oJson["test_int"](i) << std::endl;
     }
     oJson.AddNull("null_value");
     std::cout << oJson.IsNull("test_float") << "\t" << oJson.IsNull("null_value") << std::endl;
     oJson["test_float"].AddNull();
     std::cout << oJson.ToString() << std::endl;

     if (oJson.KeyExist("simeout"))
         std::cout << "timeout key exist" << std::endl;

     neb::CJsonObject oLongLong("{\"long_long\":1283949231388184576}");
     int64 llValue = 0;
     uint64 ullValue = 0;
     oLongLong.Get("long_long", llValue);
     oLongLong.Get("long_long", ullValue);
     std::cout << "llValue = " << llValue << ",  ullValue = " << ullValue << std::endl;
     //oJson.Add("json_move", std::move(oLongLong)); // C++11
     oJson.AddWithMove("json_move", oLongLong);  
     std::cout << oJson.ToString() << std::endl;
}

