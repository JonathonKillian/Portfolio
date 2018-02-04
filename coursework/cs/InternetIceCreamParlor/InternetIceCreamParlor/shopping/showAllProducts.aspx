<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="showAllProducts.aspx.cs" Inherits="InternetIceCreamParlor.shopping.showAllProducts" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
	<link rel="stylesheet" type="text/css" href="~/css/styles.css" />
	<title>Product Catalog</title>
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
		Products<br />
		Deals<br />
		About<br class="dropem" />
		<%--Send status through url so main page knows to logout--%>
		<asp:HyperLink ID="lnkLogout" runat="server" NavigateUrl="~\index.aspx?status=logout">
			Logout
		</asp:HyperLink><br />
		<%--<asp:LinkButton ID="btnLogout" Text="Logout" OnClick="btnLogout_Click" runat="server" />--%>
		<asp:HyperLink ID="lnkSignup" runat="server" NavigateUrl="userManagement\createUser.aspx">
			Sign up
		</asp:HyperLink>
	</nav>
	<main>
		<asp:Label ID="lblGreet" runat="server" />
		<br />
		<asp:Table ID="tblProducts" runat="server">
			<asp:TableHeaderRow runat="server" TableSection="TableHeader">
				<asp:TableHeaderCell runat="server" Scope="Column">Product</asp:TableHeaderCell>
				<asp:TableHeaderCell runat="server" Scope="Column">Description</asp:TableHeaderCell>
				<asp:TableHeaderCell runat="server" Scope="Column">Price</asp:TableHeaderCell>
				<asp:TableHeaderCell runat="server" Scope="Column">Buy</asp:TableHeaderCell>
			</asp:TableHeaderRow>
		</asp:Table>
	</main>

	<footer>
		Copyright &ndash; Feedback &ndash; Contact &ndash; Mailing list
	</footer>
</body>
</html>
