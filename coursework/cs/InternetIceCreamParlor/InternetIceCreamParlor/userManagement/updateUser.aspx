<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="updateUser.aspx.cs" Inherits="InternetIceCreamParlor.updateUser" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
	<link rel="stylesheet" type="text/css" href="../css/userManagement.css" />
    <title>Update User</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
		<asp:label id="lblFName" runat="server" text="First Name" AssociatedControlID="txtFName"/>
		<asp:TextBox id="txtFName" runat="server" />
		<br />
		<asp:label id="lblLName" runat="server" text="Last Name" AssociatedControlID="txtLName"/>
		<asp:TextBox id="txtLName" runat="server" />
		<br />
		<asp:label id="lblUser" runat="server" text="User Name" AssociatedControlID="txtUser"/>
		<asp:TextBox id="txtUser" runat="server" />
		<br />
		<asp:label id="lblPassword" runat="server" text="Password" AssociatedControlID="txtPassword"/>
		<asp:TextBox id="txtPassword" runat="server" />
		<br />
		<asp:label id="lblAddress" runat="server" text="Address" AssociatedControlID="txtAddress"/>
		<asp:TextBox id="txtAddress" runat="server" />
		<br />
		<asp:label id="lblEmail" runat="server" text="Email" AssociatedControlID="txtEmail"/>
		<asp:TextBox id="txtEmail" runat="server" />
		<br />
		<asp:label id="lblPhone" runat="server" text="Phone" AssociatedControlID="txtPhone"/>
		<asp:TextBox id="txtPhone" runat="server" />
		<br class="newline"/>
    </div>
		<asp:Button id="btnUpdate" runat="server" text="Update" onClick="btnUpdate_Click" />
    </form>
</body>
</html>
