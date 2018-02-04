<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="newProduct.aspx.cs" Inherits="InternetIceCreamParlor.productManagement.newProduct" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
	<link rel="stylesheet" type="text/css" href="../css/styles.css" />
    <title>New Product</title>
</head>
<body>
	<div id="banner">
		<img src="../img/neonicecream.png" />
	</div>

	<nav>
		<asp:Hyperlink ID="lnkMain" runat="server" NavigateUrl="~\index.aspx">
			Main
		</asp:Hyperlink><br />
		New Products<br />
		<asp:Hyperlink ID="lnkProducts" runat="server" NavigateUrl="~\shopping\showAllProducts.aspx">
			Products
		</asp:Hyperlink><br />
		Deals<br />
		About<br class="dropem" />
		<%--Send status through url so main page knows to logout--%>
		<asp:HyperLink ID="lnkLogout" runat="server" NavigateUrl="~\index.aspx?status=logout">
			Logout
		</asp:HyperLink><br />
		<asp:HyperLink ID="lnkSignup" runat="server" NavigateUrl="~\userManagement\createUser.aspx">
			Sign up
		</asp:HyperLink>
	</nav>

	<main>
		<asp:Label ID="lblGreet" runat="server" />
		<br class="dropem" />

		<form id="frmProduct" runat="server">
		<div>
			<asp:label id="lblProduct" runat="server" text="Product Name" AssociatedControlID="txtProduct"/>
			<asp:TextBox id="txtProduct" runat="server" />
			<br />
			<asp:label id="lblDescription" runat="server" text="Description" AssociatedControlID="txtDescription"/>
			<asp:TextBox id="txtDescription" runat="server" />
			<br />
			<asp:label id="lblPrice" runat="server" text="Price" AssociatedControlID="txtPrice"/>
			<asp:TextBox id="txtPrice" runat="server" />
			<asp:RegularExpressionValidator runat="server"
				ControlToValidate="txtPrice"
				ValidationExpression="^\+?\d*\.?\d+$"
				Display="Dynamic" ForeColor="Red"
				ErrorMessage="Please enter a numeric price (no $)" />
			<br />
			<asp:label id="lblAmount" runat="server" text="Amount" AssociatedControlID="txtAmount"/>
			<asp:TextBox id="txtAmount" runat="server" />
			<asp:RegularExpressionValidator runat="server"
				ControlToValidate="txtAmount"
				ValidationExpression="^[1-9]\d*$"
				Display="Dynamic" ForeColor="Red"
				ErrorMessage="Please enter a positive whole number amount" />
			<%--Since the regex doesn't allow 0, make field required--%>
			<asp:RequiredFieldValidator runat="server"
				ControlToValidate="txtAmount"
				Display="Dynamic" ForeColor="Red"
				ErrorMessage="Please enter a positive whole number amount" />
		</div>
		<asp:Button id="btnAddProduct" runat="server" text="Add Product" OnClick="btnProduct_Click" />
		</form>
	</main>

	<footer>
		Copyright &ndash; Feedback &ndash; Contact &ndash; Mailing list
	</footer>
</body>
</html>
