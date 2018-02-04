<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="index.aspx.cs" Inherits="InternetIceCreamParlor.index" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
	<link rel="stylesheet" type="text/css" href="css/styles.css" />
	<title>Ice Cream Internet Parlor</title>
</head>
<body>
    <!--
        Source for banner image: https://pixabay.com/en/ice-cream-advert-announcement-676470/
        CC0 Creative Commons: Free for commerical use, no attribution required
     -->
	<div id="banner">
		<img src="img/neonicecream.png" />
	</div>
	<nav>
		<asp:Hyperlink ID="lnkMain" runat="server" NavigateUrl="~\index.aspx">
			Main
		</asp:Hyperlink><br />
		<asp:Hyperlink ID="lnkNewProduct" runat="server" NavigateUrl="~\productManagement\newProduct.aspx">
			New Products
		</asp:Hyperlink><br />
		<asp:Hyperlink ID="lnkProducts" runat="server" NavigateUrl="~\shopping\showAllProducts.aspx">
			Products
		</asp:Hyperlink><br />
		Deals<br />
		About<br class="dropem" />
	</nav>
	<main>
		<asp:Label ID="lblGreet" runat="server" />
	</main>
	<form id="frmLogin" runat="server">
		<fieldset id="fstBox" runat="server">
			<asp:TextBox ID="txtUser" placeholder="User Name" runat="server" />
			<br />
			<asp:TextBox ID="txtPassword" TextMode="Password" runat="server" />
			<br />
			<asp:Button ID="btnLogin" Text="Login" OnClick="btnLogin_Click" runat="server" />
		</fieldset>
		<asp:LinkButton ID="btnLogout" Text="Logout" OnClick="btnLogout_Click" Visible="false" runat="server" />
	</form>
	<asp:HyperLink ID="lnkSignup" runat="server" NavigateUrl="userManagement\createUser.aspx">
		Sign up
	</asp:HyperLink>

	<footer>
		Copyright &ndash; Feedback &ndash; Contact &ndash; Mailing list
	</footer>
</body>
</html>
