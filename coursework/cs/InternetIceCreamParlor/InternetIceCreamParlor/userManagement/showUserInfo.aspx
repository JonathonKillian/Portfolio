<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="showUserInfo.aspx.cs" Inherits="InternetIceCreamParlor.showUserInfo" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
	<link rel="stylesheet" type="text/css" href="../css/userManagement.css" />
	<title>Show Updated Info</title>
</head>
<body>
	<%--<form id="form1" runat="server">--%>
	<div>
		<asp:label runat="server" text="First Name" cssclass="query" />
		<asp:label id="lblFName" runat="server" />
		<br />
		<asp:label runat="server" text="Last Name" cssclass="query" />
		<asp:label id="lblLName" runat="server" />
		<br />
		<asp:label runat="server" text="User Name" cssclass="query" />
		<asp:label id="lblUser" runat="server" />
		<br />
		<asp:label runat="server" text="Password" cssclass="query" />
		<asp:label id="lblPassword" runat="server" />
		<br />
		<asp:label runat="server" text="Address" cssclass="query" />
		<asp:label id="lblAddress" runat="server" />
		<br />
		<asp:label runat="server" text="Email" cssclass="query" />
		<asp:label id="lblEmail" runat="server" />
		<br />
		<asp:label runat="server" text="Phone" cssclass="query" />
		<asp:label id="lblPhone" runat="server" />
    </div>
	<asp:HyperLink ID="lnkHome" runat="server" NavigateUrl="../index.aspx">
		Home
	</asp:HyperLink>
    <%--</form>--%>
</body>
</html>
