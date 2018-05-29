<!--
Copyright (c) Microsoft Corporation.  All rights reserved.
-->
<!--
Use of this source code is subject to the terms of the Microsoft end-user
license agreement (EULA) under which you licensed this SOFTWARE PRODUCT.
If you did not accept the terms of the EULA, you are not authorized to use
this source code. For a copy of the EULA, please see the LICENSE.RTF on your
install media.
-->
<%@ LANGUAGE = JSCRIPT %>

<html>
<head>
<title>EZForeocurt view pumps</title>
<meta http-equiv="refresh" content="3">
    <style type="text/css">
        .style1
        {
            width: 178px;
        }
    </style>
</head>

<body>

<body bgcolor="#FFFFFF" link="#0000FF" vlink="#800080">
<font size="5"><font STYLE="Tahoma"></font>

<p align="center">
<table align=center width=50%>
<tr><td valign=middle width=50%>
<a
        href="http://EZTech.com.br"><img
        src="eztech.bmp" alt="EZTech Ltda" border="0"
        width="102" height="48"></a>
</td><td valign=middle width=50%>
        <font size="5"><b>View Pumps</b> </font>
</td>
</tr>
</table>


</p>
<HR>
<p align="center"><font size="4">
<br></b>

<% var Pumps = new ActiveXObject("HttpdPumps") %>

<TABLE BORDER=1 WIDTH=90%>
<THEAD>
<TR>
<TH WIDTH=5% align="right">No.</TH>
<TH WIDTH=13%>Name</TH>
<TH WIDTH=30%>State</TH>
<TH WIDTH=12%>Grade</TH>
<TH WIDTH=10% align="right">Price</TH>
<TH WIDTH=10% align="right">Value</TH>
<TH WIDTH=10% align="right">Volume</TH>
<TH WIDTH=10%>Stack</TH>
</TR>
<TBODY>

<%

    Pumps.First() ;
    
    for (i = 0; i < Pumps.Count; i++)
    {
    	Pumps.Increment();
	
%>

<TR>
<FORM ACTION = "Pumps.asp" METHOD = "post">
<TD align="right"><%= Pumps.Number %></TD>
<TD><%= Pumps.Name %></TD>
<TD><%= Pumps.State %></TD>
<TD><%= Pumps.CurGrade %></TD>
<TD align="right"><%=Pumps.CurPriceStr %></TD>
<TD align="right"><%=Pumps.CurValueStr %></TD>
<TD align="right"><%=Pumps.CurVolumeStr %></TD>
<TD><%= Pumps.StackSizeStr %></TD>
</FORM>
</TR>

<%
	// End of for loop
	}
%>

</TABLE>

<p align="center"><font size="4">
<br></b>
<HR>
<p align="center"><font size="4">
<BR>Back to <a href="default.htm">main page</a>.
<!--  Don't need to free the HttpVRoots object, ASP does this automatically -->
</body>
</html>



