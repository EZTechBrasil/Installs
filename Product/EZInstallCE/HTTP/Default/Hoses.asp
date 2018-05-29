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
<title>EZForeocurt view Hoses</title>
<meta http-equiv="refresh" content="15">
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
        <font size="5"><b>View Hoses</b> </font>
</td>
</tr>
</table>


</p>
<HR>
<p align="center"><font size="4">
<br></b>

<% var Hoses = new ActiveXObject("HttpdHoses") %>

<TABLE BORDER=1 WIDTH=70%>
<THEAD>
<TR>
<TH WIDTH=10% align="right">No.</TH>
<TH WIDTH=25%>Pump</TH>
<TH WIDTH=25%>Grade</TH>
<TH WIDTH=20% align="right">Volume ETotal</TH>
<TH WIDTH=20% align="right">Value ETotal</TH>
</TR>
<TBODY>

<%

    Hoses.First() ;
    
    for (i = 0; i < Hoses.Count; i++)
    {
    	Hoses.Increment();
	
%>

<TR>
<FORM ACTION = "Hoses.asp" METHOD = "post">
<TD align="right"><%= Hoses.PhysicalNumber %></TD>
<TD><%= Hoses.PumpName %></TD>
<TD><%= Hoses.GradeName %></TD>
<TD align="right"><%=Hoses.VolumeETotStr %></TD>
<TD align="right"><%=Hoses.ValueETotStr %></TD>
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



