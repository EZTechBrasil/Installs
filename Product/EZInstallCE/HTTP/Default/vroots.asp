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
<title>Windows CE Web Manager - Modify Virtual Roots Settings</title>
</head>

<body>
<B>View and modify Windows CE Web Server Virtual Roots Page</B>
<BR>Virtual roots specify the mapping between a directory as requested
by a web browser and the physical location of the directory on the device.
For instance, if a virtual path is set as 
"/" and the physical path is "\windows\www", a request for file 
http://WebServer/file.htm will retrieve the file \windows\www\file.htm.  It is
possible to have multiple virtual roots mapped to multiple directories on the 
Web Server.

<P>Authorization level Public means everyone has access to pages 
under that directory.  If authorization level User is set, the web server will 
require a valid username and password to grant access to pages.  Whether 
<B>Basic</B> or <B>NTLM</B> authentication is used can be set on the 
<a href="settings.asp">Settings Page</a>

<P>If authorization level is set to Administrator, the web server will first 
make sure the user has authorization User priveleges.  Then it will look
for the user's name <B>AdminUsers</B>, which can be set on the 
<a href="settings.asp">Settings Page</a>

<P>In order to execute an ISAPI Extension, the directory it's in must have Execute Access
enabled (by selecting yes in the appropriate row of the table below).  To execute an
ASP page, the directory it's in must have either Script Access or Execute Access enabled.


<HR>
Modify the virtual roots rows one at a time, selecting the modify or add button when through
making changes on that row.  The settings will not take affect until the next time the server
is restarted.
<%  var VirtualRoots = new ActiveXObject("HttpdVRoots");

	if ( Request.Form.Count != 0)
	{
		// VirtualPath must be set before any of the other values!

		VirtualRoots.VirtualPath 	= Request.Form("VirtualPath");

		if ( Request.Form("Action") == "Delete")
		{
			VirtualRoots.DeleteRoot();
		}
		else
		{
			VirtualRoots.PhysicalPath 	= Request.Form("PhysicalPath");
			VirtualRoots.ReadAccess     = Request.Form("ReadAccess");
			VirtualRoots.ScriptAccess   = Request.Form("ScriptAccess");
			VirtualRoots.ExecuteAccess	= Request.Form("ExecuteAccess");
			VirtualRoots.AuthRequired	= Request.Form("AuthRequired");
		}
	}
%>

<TABLE BORDER=1 WIDTH=80%>
<THEAD>
<TR>
<TH>Virtual Path</TH>
<TH>Physical Path</TH>
<TH>Authorization</TH>
<TH>Read <BR>Access</TH>
<TH>Execute <BR>Access</TH>
<TH>Script <BR>Access</TH>
<TH>Modify</TH>
<TH>Delete</TH>
</TR>
<TBODY>



<%
    for (i = 0; i < VirtualRoots.Count; i++)
    {
    	VirtualRoots.Increment();
	
%>

<TR>
<FORM ACTION = "vroots.asp" METHOD = "post">
<TD><INPUT NAME = "VirtualPath"  READONLY VALUE = "<%= VirtualRoots.VirtualPath  %>">  </TD>
<TD><INPUT NAME = "PhysicalPath" VALUE = "<%= VirtualRoots.PhysicalPath %>">  </TD>

<TD>
<SELECT NAME = "AuthRequired">

<% authRequired = VirtualRoots.AuthRequired; %>
<%  if (authRequired == 0) %>
<OPTION VALUE="0" SELECTED>Public
<OPTION VALUE="1">		   User
<OPTION VALUE="2">		   Administrator
<% %>

<% if (authRequired == 1) %>
<OPTION VALUE="0">			Public
<OPTION VALUE="1" SELECTED> User 
<OPTION VALUE="2">			Administrator
<% %>

<% if (authRequired >= 2) %>
<OPTION VALUE="0">			Public
<OPTION VALUE="1">			User 
<OPTION VALUE="2" SELECTED> Administrator
<% %>

</OPTION>
</SELECT>
</TD>


<TD>
<% if (VirtualRoots.ReadAccess == 1) %>
Yes   <INPUT type="radio" name=ReadAccess VALUE="1" Checked>		
<BR>No<INPUT type="radio" name=ReadAccess VALUE="0" >

<% else %>
Yes   <INPUT type="radio" name=ReadAccess VALUE="1" >		
<BR>No<INPUT type="radio" name=ReadAccess VALUE="0" Checked >
<% %>
</TD>

<TD>
<% if (VirtualRoots.ExecuteAccess == 1) %>
Yes   <INPUT type="radio" name=ExecuteAccess VALUE="1" Checked>		
<BR>No<INPUT type="radio" name=ExecuteAccess VALUE="0" >

<% else %>
Yes   <INPUT type="radio" name=ExecuteAccess VALUE="1" >		
<BR>No<INPUT type="radio" name=ExecuteAccess VALUE="0" Checked >
<% %>
</TD>


<TD>
<% if (VirtualRoots.ScriptAccess == 1) %>
Yes   <INPUT type="radio" name=ScriptAccess VALUE="1" Checked>		
<BR>No<INPUT type="radio" name=ScriptAccess VALUE="0" >

<% else %>
Yes   <INPUT type="radio" name=ScriptAccess VALUE="1" >		
<BR>No<INPUT type="radio" name=ScriptAccess VALUE="0" Checked >
<% %>
</TD>


<TD><INPUT TYPE = submit NAME="Action" VALUE="Modify"></TD>
<TD><INPUT TYPE = submit NAME="Action" VALUE="Delete"></TD>
</FORM>
</TR>

<%
	// End of for loop
	}
%>

<!-- The last row in this table is used to Add new Vroots. -->
<TR>
<FORM ACTION = "vroots.asp" METHOD = "post">
<TD><INPUT NAME = "VirtualPath"  value = "Add new virtual path"</TD>
<TD><INPUT NAME = "PhysicalPath" value = "Add new physical path"</TD>

<TD>
<SELECT NAME = "AuthRequired">
<OPTION VALUE="0">Public
<OPTION VALUE="1">User 
<OPTION VALUE="2">Administrator
</OPTION>
</SELECT>
</TD>

<TD>
    Yes<INPUT type="radio" name=ReadAccess VALUE="1" CHECKED>
<BR>No<INPUT type="radio" name=ReadAccess VALUE="0" >
</TD>

<TD>
    Yes<INPUT type="radio" name=ExecuteAccess VALUE="1" CHECKED >
<BR>No<INPUT type="radio" name=ExecuteAccess VALUE="0">
</TD>


<TD>
    Yes<INPUT type="radio" name=ScriptAccess VALUE="1" CHECKED >
<BR>No<INPUT type="radio" name=ScriptAccess VALUE="0">
</TD>


<TD><INPUT TYPE = submit VALUE="Add"></TD>
</FORM>
</TR>
</TABLE>

<BR>Go to the <a href="default.htm">main page</a>.
<!--  Don't need to free the HttpVRoots object, ASP does this automatically -->
</body>
</html>



