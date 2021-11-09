<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="zh_CN" sourcelanguage="en">
<context>
    <name>SerialAssistant</name>
    <message>
        <source>MainWindow</source>
        <translation type="vanished">硬石电子-SerialAssistant v2.0</translation>
    </message>
    <message>
        <source>Hex</source>
        <oldsource>Hex显示</oldsource>
        <translation type="vanished">Hex显示</translation>
    </message>
    <message>
        <location filename="../ui/serialassistant.ui" line="470"/>
        <source> from left</source>
        <translation> 开始</translation>
    </message>
    <message>
        <location filename="../ui/serialassistant.ui" line="498"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;* not include the n&lt;/p&gt;&lt;p&gt;* the priority of &lt;span style=&quot; font-weight:600;&quot;&gt;inset verify &lt;/span&gt;is lower than &lt;span style=&quot; font-weight:600;&quot;&gt;add Treminator&lt;/span&gt;,when &lt;span style=&quot; font-weight:600;&quot;&gt;insert verify&lt;/span&gt;,there will be &lt;span style=&quot; font-weight:600;&quot;&gt;Treminator(CR,LF or CRLF)&lt;/span&gt; at the end of the &lt;span style=&quot; font-weight:600;&quot;&gt;str &lt;/span&gt;if the combox is not default.&lt;/p&gt;&lt;p&gt;&lt;br/&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <oldsource>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;the priority of &lt;span style=&quot; font-weight:600;&quot;&gt;inset verify &lt;/span&gt;is lower than &lt;span style=&quot; font-weight:600;&quot;&gt;add Treminator&lt;/span&gt;,when &lt;span style=&quot; font-weight:600;&quot;&gt;insert verify&lt;/span&gt;,there will be &lt;span style=&quot; font-weight:600;&quot;&gt;Treminator(CR,LF or CRLF)&lt;/span&gt; at the end of the &lt;span style=&quot; font-weight:600;&quot;&gt;str &lt;/span&gt;if the combox is not default.&lt;/p&gt;&lt;p&gt;&lt;br/&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</oldsource>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;* 不包括第n个字节&lt;/p&gt;&lt;p&gt; &lt;span style=&quot; font-weight:600;&quot;&gt; 插入校验码 &lt;/span&gt; 的优先级比 &lt;span style=&quot; font-weight:600;&quot;&gt;添加结束符&lt;/span&gt;要低,当使用 &lt;span style=&quot; font-weight:600;&quot;&gt;插入校验码时&lt;/span&gt;,需要考虑 &lt;span style=&quot; font-weight:600;&quot;&gt;Treminator(CR,LF or CRLF)&lt;/span&gt; 的长度.&lt;/p&gt;&lt;p&gt;&lt;br/&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../ui/serialassistant.ui" line="507"/>
        <source> from right</source>
        <translation> 个前</translation>
    </message>
    <message>
        <location filename="../ui/serialassistant.ui" line="510"/>
        <source>end with </source>
        <translation>至倒数第 </translation>
    </message>
    <message>
        <location filename="../ui/serialassistant.ui" line="532"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;ADD8:&lt;/span&gt;将数据累加,取低8位&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;NADD8:&lt;/span&gt;将数据累加,取低8位,然后取反加1（0-ADD8）&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;XOR8:&lt;/span&gt;将8位数据异或&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;CRC16_Modbus:&lt;/span&gt;用于Modbus-RTU协议,输出字节反序,低位字节在前,高位字节在后&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;CRC16_CCITT:&lt;/span&gt;多项式0x1021,常用的CRC校验之一&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;CRC16_CCITT_FALSE:&lt;/span&gt;多项式0x1021,常用的CRC校验之一&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;CRC16_USB:&lt;/span&gt;用于USB通信协议&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;CRC32:&lt;/span&gt;多项式0x04C11DB7 IEEE 802.3标准&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;LRC:&lt;/span&gt;NADD8的字符模式,专用于字符发送模式,只会统计字符串中HEX格式的数据,校验算法与NADD8一致,得到的1字节再分拆成两个ASCII字符(用于Mosbus-ASCII)&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;ADD8:&lt;/span&gt;将数据累加,取低8位&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;NADD8:&lt;/span&gt;将数据累加,取低8位,然后取反加1（0-ADD8）&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;XOR8:&lt;/span&gt;将8位数据异或&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;CRC16_Modbus:&lt;/span&gt;用于Modbus-RTU协议,输出字节反序,低位字节在前,高位字节在后&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;CRC16_CCITT:&lt;/span&gt;多项式0x1021,常用的CRC校验之一&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;CRC16_CCITT_FALSE:&lt;/span&gt;多项式0x1021,常用的CRC校验之一&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;CRC16_USB:&lt;/span&gt;用于USB通信协议&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;CRC32:&lt;/span&gt;多项式0x04C11DB7 IEEE 802.3标准&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-weight:600;&quot;&gt;LRC:&lt;/span&gt;NADD8的字符模式,专用于字符发送模式,只会统计字符串中HEX格式的数据,校验算法与NADD8一致,得到的1字节再分拆成两个ASCII字符(用于Mosbus-ASCII)&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../ui/serialassistant.ui" line="575"/>
        <source> ms</source>
        <translatorcomment>毫秒</translatorcomment>
        <translation> ms</translation>
    </message>
    <message>
        <location filename="../ui/serialassistant.ui" line="645"/>
        <source>GB18030</source>
        <translation>GB18030</translation>
    </message>
    <message>
        <location filename="../ui/serialassistant.ui" line="667"/>
        <source>UTF-8</source>
        <translation>UTF-8</translation>
    </message>
    <message>
        <location filename="../ui/serialassistant.ui" line="829"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;&lt;a href=&quot;http://www.ing10bbs.com/forum.php&quot;&gt;&lt;span style=&quot; font-size:10pt; text-decoration: underline; color:#3da5ff;&quot;&gt;Download reference &lt;/span&gt;&lt;/a&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <oldsource>&lt;html&gt;
  &lt;head/&gt;
    &lt;body&gt;
      &lt;p&gt;
        &lt;a href=&quot;http://www.ing10bbs.com/forum.php&quot;&gt;
          &lt;span style=&quot; font-size:10pt; text-decoration: underline;               color:#3da5ff;&quot;&gt;开源资料下载
          &lt;/span&gt;
        &lt;/a&gt;
      &lt;/p&gt;
    &lt;/body&gt;
&lt;/html&gt;</oldsource>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;&lt;a href=&quot;http://www.ing10bbs.com/forum.php&quot;&gt;&lt;span style=&quot; font-size:10pt; text-decoration: underline; color:#3da5ff;&quot;&gt;下载更多资料&lt;/span&gt;&lt;/a&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../ui/serialassistant.ui" line="102"/>
        <source>Receive</source>
        <translation>接收显示</translation>
    </message>
    <message>
        <location filename="../ui/serialassistant.ui" line="44"/>
        <source>Communication parameter</source>
        <translation>通信参数配置</translation>
    </message>
    <message>
        <location filename="../ui/serialassistant.ui" line="140"/>
        <source>Hex Display</source>
        <translation>Hex显示</translation>
    </message>
    <message>
        <location filename="../ui/serialassistant.ui" line="153"/>
        <source>timestamp</source>
        <translation>插入时间戳</translation>
    </message>
    <message>
        <location filename="../ui/serialassistant.ui" line="208"/>
        <source>Reset counter</source>
        <translation>重置计数器</translation>
    </message>
    <message>
        <location filename="../ui/serialassistant.ui" line="264"/>
        <source>Save to file</source>
        <translation>保存至文件</translation>
    </message>
    <message>
        <location filename="../ui/serialassistant.ui" line="290"/>
        <source>clear</source>
        <translation>清空</translation>
    </message>
    <message>
        <location filename="../ui/serialassistant.ui" line="331"/>
        <location filename="../ui/serialassistant.ui" line="428"/>
        <location filename="../ui/serialassistant.ui" line="806"/>
        <source>Transmit</source>
        <translation>发送控制</translation>
    </message>
    <message>
        <location filename="../ui/serialassistant.ui" line="369"/>
        <source>add terminator</source>
        <oldsource>add character at end</oldsource>
        <translation>添加结束符</translation>
    </message>
    <message>
        <location filename="../ui/serialassistant.ui" line="402"/>
        <source>load</source>
        <translation>加载文件</translation>
    </message>
    <message>
        <location filename="../ui/serialassistant.ui" line="461"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;include the n &lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <oldsource>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;include n byte&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</oldsource>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;包括第 n 个字节&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source> byte</source>
        <translation type="vanished"> 开始</translation>
    </message>
    <message>
        <location filename="../ui/serialassistant.ui" line="473"/>
        <source>satrt with </source>
        <translation>从第 </translation>
    </message>
    <message>
        <source>before </source>
        <translation type="vanished">至倒数第 </translation>
    </message>
    <message>
        <location filename="../ui/serialassistant.ui" line="545"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;the verify code will inset at the str to transmit&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;显示计算得到的校验码&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../ui/serialassistant.ui" line="569"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;at least 20ms&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>至少 20 ms</translation>
    </message>
    <message>
        <location filename="../ui/serialassistant.ui" line="578"/>
        <source>Transmit interval </source>
        <translation>发送时间间隔 </translation>
    </message>
    <message>
        <location filename="../ui/serialassistant.ui" line="605"/>
        <source>Hex Send</source>
        <translation>Hex发送</translation>
    </message>
    <message>
        <location filename="../ui/serialassistant.ui" line="618"/>
        <source>Auto Transmit</source>
        <translation>定时发送</translation>
    </message>
    <message>
        <location filename="../ui/serialassistant.ui" line="629"/>
        <source>Character encoding</source>
        <translation>字符编码</translation>
    </message>
    <message>
        <location filename="../ui/serialassistant.ui" line="785"/>
        <source>Single</source>
        <translation>单帧发送</translation>
    </message>
    <message>
        <location filename="../ui/serialassistant.ui" line="803"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Transmit&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;发送&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../ui/serialassistant.ui" line="845"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;&lt;a href=&quot;https://shop149744403.taobao.com/&quot;&gt;&lt;span style=&quot; font-size:10pt; text-decoration: underline; color:#3da5ff;&quot;&gt;Buy F1-Pro/F4-Pro/&lt;/span&gt;&lt;/a&gt;&lt;/p&gt;&lt;p&gt;&lt;a href=&quot;https://shop149744403.taobao.com/&quot;&gt;&lt;span style=&quot; font-size:10pt; text-decoration: underline; color:#3da5ff;&quot;&gt;H7-Pro/H7-Multi&lt;/span&gt;&lt;/a&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;&lt;a href=&quot;https://shop149744403.taobao.com/&quot;&gt;&lt;span style=&quot; font-size:10pt; text-decoration: underline; color:#3da5ff;&quot;&gt;开发板购买链接&lt;/span&gt;&lt;/a&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../ui/serialassistant.ui" line="892"/>
        <source>Multi</source>
        <translation>多帧发送</translation>
    </message>
    <message>
        <location filename="../ui/serialassistant.ui" line="1023"/>
        <source>繁體中文</source>
        <translation>繁體中文</translation>
    </message>
    <message>
        <location filename="../ui/serialassistant.ui" line="1028"/>
        <source>Windows</source>
        <translation>Windows</translation>
    </message>
    <message>
        <location filename="../ui/serialassistant.ui" line="1033"/>
        <source>WindowsVista</source>
        <translation>WindowsVista</translation>
    </message>
    <message>
        <location filename="../ui/serialassistant.ui" line="1038"/>
        <source>DarkStyle</source>
        <translation>DarkStyle</translation>
    </message>
    <message>
        <location filename="../ui/serialassistant.ui" line="1043"/>
        <source>DefaultStyle</source>
        <translation>DefaultStyle</translation>
    </message>
    <message>
        <source>帮助</source>
        <translation type="vanished">帮助</translation>
    </message>
    <message>
        <location filename="../ui/serialassistant.ui" line="975"/>
        <source>语言(language)</source>
        <translation>语言(language)</translation>
    </message>
    <message>
        <source>Rename</source>
        <translation type="vanished">重命名</translation>
    </message>
    <message>
        <location filename="../ui/serialassistant.ui" line="950"/>
        <location filename="../ui/serialassistant.ui" line="988"/>
        <location filename="../ui/serialassistant.ui" line="991"/>
        <source>Help</source>
        <translation>帮助</translation>
    </message>
    <message>
        <location filename="../ui/serialassistant.ui" line="1018"/>
        <source>fusion</source>
        <translation>fusion</translation>
    </message>
    <message>
        <source>window</source>
        <translation type="vanished">window</translation>
    </message>
    <message>
        <source>繁体中文</source>
        <translation type="vanished">繁体中文</translation>
    </message>
    <message>
        <source>硬石电子-SerialAssistant v2.0</source>
        <translation type="vanished">硬石电子-串口调试助手 v2.0</translation>
    </message>
    <message>
        <location filename="../src/serialassistant.cpp" line="104"/>
        <source> insert verify</source>
        <translation> 插入校验码</translation>
    </message>
    <message>
        <location filename="../src/serialassistant.cpp" line="191"/>
        <location filename="../src/serialassistant.cpp" line="366"/>
        <source>unsupported input</source>
        <translation>不支持的输入</translation>
    </message>
    <message>
        <source>Only the input of the [0~9], [a~f], [A-F], and spaces is supported</source>
        <translation type="vanished">仅支持输入[0~9],[a~f],[A~F]和空格</translation>
    </message>
    <message>
        <location filename="../src/serialassistant.cpp" line="366"/>
        <source>Please enter the full byte</source>
        <translation>请输入完整的Hex字符</translation>
    </message>
    <message>
        <location filename="../src/serialassistant.cpp" line="611"/>
        <source>the new data will be save on %1,and it does not appear on the software.</source>
        <translation>新接收的数据将会被保存在 %1,并且不会再软件界面中显示出来.</translation>
    </message>
    <message>
        <source>so check the dasplay before proceeding.</source>
        <translation type="vanished">所以在操作前要先检查显示样式.</translation>
    </message>
    <message>
        <source>硬石电子-SerialAssistant v2.0.1</source>
        <translation type="obsolete">硬石电子-串口调试助手 v2.0.1</translation>
    </message>
    <message>
        <source>\硬石电子-SerialAssistant v2.0.1</source>
        <translation type="obsolete">\硬石电子-串口调试助手</translation>
    </message>
    <message>
        <location filename="../src/serialassistant.cpp" line="78"/>
        <source>\硬石电子-SerialAssistant</source>
        <translation>\硬石电子-串口调试助手</translation>
    </message>
    <message>
        <location filename="../src/serialassistant.cpp" line="191"/>
        <source>Only the [0~9], [a~f], [A~F], and spaces is supported</source>
        <translation>仅支持[0~9],[a~f],[A~F],和空格</translation>
    </message>
    <message>
        <location filename="../src/serialassistant.cpp" line="612"/>
        <source>so check the dasplay before continue.</source>
        <translation>所以在运行前需要先检查显示样式.</translation>
    </message>
    <message>
        <location filename="../src/serialassistant.cpp" line="622"/>
        <source>save to file</source>
        <translation>保存至文件</translation>
    </message>
    <message>
        <location filename="../src/serialassistant.cpp" line="638"/>
        <source>Open file</source>
        <translation>打开文件</translation>
    </message>
    <message>
        <location filename="../src/serialassistant.cpp" line="647"/>
        <location filename="../src/serialassistant.cpp" line="649"/>
        <source>The file size:</source>
        <translation>文件大小:</translation>
    </message>
    <message>
        <location filename="../src/serialassistant.cpp" line="660"/>
        <source>Load the file</source>
        <translation>加载文件</translation>
    </message>
    <message>
        <location filename="../src/serialassistant.cpp" line="688"/>
        <location filename="../src/serialassistant.cpp" line="739"/>
        <source>Transfer the file</source>
        <translation>发送文件</translation>
    </message>
    <message>
        <location filename="../src/serialassistant.cpp" line="708"/>
        <source>Stop the transfer</source>
        <translation>停止发送</translation>
    </message>
</context>
</TS>
