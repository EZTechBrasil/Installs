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
<title>Windows CE Web Manager - Modify Basic Settings</title>
</head>

<body>
<B>View and modify basic settings page</B>

<%  HttpdAdmin = new ActiveXObject("HttpdSettings") %>

<% 
	// If there's data in the form request, set it.
	if ( Request.Form.Count != 0 )  
	{
		if ( Request.Form("UseLogging") == 1)
		{
			HttpdAdmin.MaxLogSize 		= Request.Form("MaxLogSize");
			HttpdAdmin.LogFileDirectory = Request.Form("LogFileDirectory");
		}
		else
		{
			HttpdAdmin.MaxLogSize = 0;
		}
		HttpdAdmin.AuthBasic 	= Request.Form("AuthBasic");
		HttpdAdmin.AuthNTLM		= Request.Form("AuthNTLM");
		HttpdAdmin.AdminUsers   = Request.Form("AdminUsers");
		HttpdAdmin.DefaultPages	= Request.Form("DefaultPages");
		HttpdAdmin.DirBrowse 	= Request.Form("DirBrowse");
	}
%>



<FORM ACTION = "settings.asp" METHOD = "post">

<TABLE BORDER=1 WIDTH=80%>
<THEAD>
<TR>
<TH>Server Variable</TH>
<TH>Value</TH>
</TR>

<TR>
<TD>Use Basic Authentication</TD>

<TD>
<% if (HttpdAdmin.AuthBasic == 1) %>
Yes   <INPUT type="radio" name=AuthBasic VALUE="1" Checked>		
<BR>No<INPUT type="radio" name=AuthBasic VALUE="0" >

<% else %>
Yes   <INPUT type="radio" name=AuthBasic VALUE="1" >		
<BR>No<INPUT type="radio" name=AuthBasic VALUE="0" Checked >
<% %>

</TD>
</TR>


<TR>
<TD>Use NTLM Authentication</TD>

<TD>
<% if (HttpdAdmin.AuthNTLM == 1) %>
Yes   <INPUT type="radio" name=AuthNTLM VALUE="1" Checked>		
<BR>No<INPUT type="radio" name=AuthNTLM VALUE="0" >
<% else %>
Yes   <INPUT type="radio" name=AuthNTLM VALUE="1" >		
<BR>No<INPUT type="radio" name=AuthNTLM VALUE="0" Checked >
<% %>

</TD>
</TR>

<TR>
<TD>Administrative users
<BR>Separate each name with a ;
</TD>
<TD><INPUT NAME = "AdminUsers" VALUE = "<%= HttpdAdmin.AdminUsers %>"></TD>
</TR>


<TR>
<TD>Allow directory browsing</TD>
<TD>
<%  if (HttpdAdmin.DirBrowse == 1) %>
Yes   <INPUT type="radio" name=DirBrowse VALUE="1" Checked>		
<BR>No<INPUT type="radio" name=DirBrowse VALUE="0" >

<% else %>
Yes   <INPUT type="radio" name=DirBrowse VALUE="1" >		
<BR>No<INPUT type="radio" name=DirBrowse VALUE="0" Checked >
<%  %>

</TD>
</TR>


<TR>
<TD>Default Pages 
<BR>Separate each page with a ;
</TD>
<TD><INPUT NAME = "DefaultPages" VALUE = "<%= HttpdAdmin.DefaultPages %>"></TD>
</TR>


<TR>
<TD>Save web activity log</TD>
<TD>
<%  if (HttpdAdmin.UseLogging == 1) %>
Yes   <INPUT type="radio" name=UseLogging VALUE="1" Checked>		
<BR>No<INPUT type="radio" name=UseLogging VALUE="0" >

<% else %>
Yes   <INPUT type="radio" name=UseLogging VALUE="1" >		
<BR>No<INPUT type="radio" name=UseLogging VALUE="0" Checked >
<% %>

</TD>
</TR>

<TR>
<TD>Maximum log size</TD>
<TD><INPUT NAME = "MaxLogSize" VALUE = "<%= HttpdAdmin.MaxLogSize %>"></TD>
</TR>

<TR>
<TD>Directory to place log files</TD>
<TD><INPUT NAME = "LogFileDirectory" VALUE = "<%= HttpdAdmin.LogFileDirectory%>"></TD>
</TR>


</TABLE>
<HR>

<P>To save changes click update.  To make changes take effect, select Start
and Restart Web Server from <a href="default.htm">the main Web Server page</a>.
<P><INPUT TYPE = submit VALUE = "Update">
</FORM>

<!--  Don't need to free the HttpAdmin object, ASP does this automatically -->
</body>
</html>


