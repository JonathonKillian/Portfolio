<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="oneclickBuy.aspx.cs" Inherits="InternetIceCreamParlor.shopping.oneclickBuy" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
	<link rel="stylesheet" type="text/css" href="~/css/styles.css" />
	<title>Purchase Confirmation</title>
</head>
<body>
	<div id="banner">
		<img src="../img/neonicecream.png" />
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
		<%--Send status through url so main page knows to logout--%>
		<asp:HyperLink ID="lnkLogout" runat="server" NavigateUrl="~\index.aspx?status=logout">
			Logout
		</asp:HyperLink><br />
		<asp:HyperLink ID="lnkSignup" runat="server" NavigateUrl="userManagement\createUser.aspx">
			Sign up
		</asp:HyperLink>
	</nav>
	<main>
		<div ID="divGreet" runat="server" />
	</main>

	<footer>
		Copyright &ndash; Feedback &ndash; Contact &ndash; Mailing list
	</footer>
</body>
</html>
