[English](/README.md) | 中文

[![](https://travis-ci.org/Bwar/CJsonObject.svg?branch=master)](https://travis-ci.org/Bwar/CJsonObject) [![Author](https://img.shields.io/badge/author-@Bwar-blue.svg?style=flat)](cqc@vip.qq.com) [![License](https://img.shields.io/github/license/mashape/apistatus.svg)](LICENSE)<br/>

[![](CJsonObject)](https://raw.githubusercontent.com/Bwar/bwar.github.io/master/style/images/logo-CJsonObject.png) <br/>

CJsonObject是Bwar基于cJSON全新开发一个C++版的JSON库，CJsonObject的最大优势是轻量、简单好用，开发效率极高，尤其对多层嵌套json的读取和生成、修改极为方便。CJsonObject比cJSON简单易用得多，且只要不是有意不释放内存就不会发生内存泄漏。用CJsonObject的好处在于完全不用专门的文档，头文件即文档，看完Demo立刻就会用，所有函数都十分通俗易懂，最为关键的一点是解析JSON和生成JSON的编码效率非常高。

CJsonObject经过5年的生产环境应用验证其功能稳定性。同时也被我倾力打造的另一个重点开源项目[Nebula](https://github.com/Bwar/Nebula)集成进去，Nebula中大量应用。

CJsonObject与fork的DaveGamble/cJSON没有任何关系，之前建立这样一个fork关系是出于对原作者的尊重，随着使用CJsonObject的开发者越来越多，CJsonObject需要自己的issue和PR，故2019-7-16下午CJsonObject解除了与cJson的fork关系，独立为一个根项目。

Bwar第一次使用cJSON是在2013年开发一个移动推送项目的时候，那时觉得cJSON虽然好用，但很容易忘了释放cJSON分配的内存。2014年Bwar在开发另一个项目时再次使用cJSON，为了提高cJSON的易用性提高开发效率对cJSON进行封装并支持64位整数，从而有了CJsonObject，在开发CJsonObject的同时对cJSON作了少量修改。

这里有个简单的[FAQ](https://github.com/Bwar/CJsonObject/wiki/FAQ)使用帮助。

