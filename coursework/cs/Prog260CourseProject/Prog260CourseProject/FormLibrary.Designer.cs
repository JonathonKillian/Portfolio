namespace Prog260CourseProject
{
	partial class FormLibrary
	{
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if(disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.labelISBN = new System.Windows.Forms.Label();
			this.textBoxISBN = new System.Windows.Forms.TextBox();
			this.textBoxTitle = new System.Windows.Forms.TextBox();
			this.labelTitle = new System.Windows.Forms.Label();
			this.textBoxAuthor = new System.Windows.Forms.TextBox();
			this.labelAuthor = new System.Windows.Forms.Label();
			this.textBoxRating = new System.Windows.Forms.TextBox();
			this.labelRating = new System.Windows.Forms.Label();
			this.textBoxPubYear = new System.Windows.Forms.TextBox();
			this.labelYear = new System.Windows.Forms.Label();
			this.buttonAddBook = new System.Windows.Forms.Button();
			this.buttonFindBook = new System.Windows.Forms.Button();
			this.buttonRemoveBook = new System.Windows.Forms.Button();
			this.listBoxISBN = new System.Windows.Forms.ListBox();
			this.buttonGetAllISBN = new System.Windows.Forms.Button();
			this.labelStatus = new System.Windows.Forms.Label();
			this.SuspendLayout();
			// 
			// labelISBN
			// 
			this.labelISBN.AutoSize = true;
			this.labelISBN.Location = new System.Drawing.Point(10, 15);
			this.labelISBN.Name = "labelISBN";
			this.labelISBN.Size = new System.Drawing.Size(35, 13);
			this.labelISBN.TabIndex = 0;
			this.labelISBN.Text = "&ISBN:";
			// 
			// textBoxISBN
			// 
			this.textBoxISBN.Location = new System.Drawing.Point(111, 12);
			this.textBoxISBN.Name = "textBoxISBN";
			this.textBoxISBN.Size = new System.Drawing.Size(100, 20);
			this.textBoxISBN.TabIndex = 1;
			this.textBoxISBN.TextChanged += new System.EventHandler(this.ValidateBoxes);
			// 
			// textBoxTitle
			// 
			this.textBoxTitle.Location = new System.Drawing.Point(111, 52);
			this.textBoxTitle.Name = "textBoxTitle";
			this.textBoxTitle.Size = new System.Drawing.Size(230, 20);
			this.textBoxTitle.TabIndex = 3;
			this.textBoxTitle.TextChanged += new System.EventHandler(this.ValidateBoxes);
			this.textBoxTitle.Enter += new System.EventHandler(this.BookFields_Enter);
			// 
			// labelTitle
			// 
			this.labelTitle.AutoSize = true;
			this.labelTitle.Location = new System.Drawing.Point(10, 55);
			this.labelTitle.Name = "labelTitle";
			this.labelTitle.Size = new System.Drawing.Size(30, 13);
			this.labelTitle.TabIndex = 2;
			this.labelTitle.Text = "&Title:";
			// 
			// textBoxAuthor
			// 
			this.textBoxAuthor.Location = new System.Drawing.Point(111, 92);
			this.textBoxAuthor.Name = "textBoxAuthor";
			this.textBoxAuthor.Size = new System.Drawing.Size(230, 20);
			this.textBoxAuthor.TabIndex = 5;
			this.textBoxAuthor.TextChanged += new System.EventHandler(this.ValidateBoxes);
			this.textBoxAuthor.Enter += new System.EventHandler(this.BookFields_Enter);
			// 
			// labelAuthor
			// 
			this.labelAuthor.AutoSize = true;
			this.labelAuthor.Location = new System.Drawing.Point(10, 95);
			this.labelAuthor.Name = "labelAuthor";
			this.labelAuthor.Size = new System.Drawing.Size(41, 13);
			this.labelAuthor.TabIndex = 4;
			this.labelAuthor.Text = "&Author:";
			// 
			// textBoxRating
			// 
			this.textBoxRating.Location = new System.Drawing.Point(111, 132);
			this.textBoxRating.Name = "textBoxRating";
			this.textBoxRating.Size = new System.Drawing.Size(100, 20);
			this.textBoxRating.TabIndex = 7;
			this.textBoxRating.TextChanged += new System.EventHandler(this.ValidateBoxes);
			this.textBoxRating.Enter += new System.EventHandler(this.BookFields_Enter);
			// 
			// labelRating
			// 
			this.labelRating.AutoSize = true;
			this.labelRating.Location = new System.Drawing.Point(10, 135);
			this.labelRating.Name = "labelRating";
			this.labelRating.Size = new System.Drawing.Size(77, 13);
			this.labelRating.TabIndex = 6;
			this.labelRating.Text = "Rating (&1 to 5):";
			// 
			// textBoxPubYear
			// 
			this.textBoxPubYear.Location = new System.Drawing.Point(111, 172);
			this.textBoxPubYear.Name = "textBoxPubYear";
			this.textBoxPubYear.Size = new System.Drawing.Size(100, 20);
			this.textBoxPubYear.TabIndex = 9;
			this.textBoxPubYear.TextChanged += new System.EventHandler(this.ValidateBoxes);
			this.textBoxPubYear.Enter += new System.EventHandler(this.BookFields_Enter);
			// 
			// labelYear
			// 
			this.labelYear.AutoSize = true;
			this.labelYear.Location = new System.Drawing.Point(10, 175);
			this.labelYear.Name = "labelYear";
			this.labelYear.Size = new System.Drawing.Size(81, 13);
			this.labelYear.TabIndex = 8;
			this.labelYear.Text = "&Year Published:";
			// 
			// buttonAddBook
			// 
			this.buttonAddBook.Location = new System.Drawing.Point(10, 210);
			this.buttonAddBook.Name = "buttonAddBook";
			this.buttonAddBook.Size = new System.Drawing.Size(75, 41);
			this.buttonAddBook.TabIndex = 10;
			this.buttonAddBook.Text = "Add &New Book";
			this.buttonAddBook.UseVisualStyleBackColor = true;
			this.buttonAddBook.Click += new System.EventHandler(this.buttonAddBook_Click);
			// 
			// buttonFindBook
			// 
			this.buttonFindBook.Location = new System.Drawing.Point(138, 210);
			this.buttonFindBook.Name = "buttonFindBook";
			this.buttonFindBook.Size = new System.Drawing.Size(75, 41);
			this.buttonFindBook.TabIndex = 11;
			this.buttonFindBook.Text = "&Find Book By ISBN";
			this.buttonFindBook.UseVisualStyleBackColor = true;
			this.buttonFindBook.Click += new System.EventHandler(this.buttonFindBook_Click);
			// 
			// buttonRemoveBook
			// 
			this.buttonRemoveBook.Location = new System.Drawing.Point(266, 210);
			this.buttonRemoveBook.Name = "buttonRemoveBook";
			this.buttonRemoveBook.Size = new System.Drawing.Size(75, 41);
			this.buttonRemoveBook.TabIndex = 12;
			this.buttonRemoveBook.Text = "&Remove Book";
			this.buttonRemoveBook.UseVisualStyleBackColor = true;
			this.buttonRemoveBook.Click += new System.EventHandler(this.buttonRemoveBook_Click);
			// 
			// listBoxISBN
			// 
			this.listBoxISBN.FormattingEnabled = true;
			this.listBoxISBN.Location = new System.Drawing.Point(382, 12);
			this.listBoxISBN.Name = "listBoxISBN";
			this.listBoxISBN.Size = new System.Drawing.Size(100, 173);
			this.listBoxISBN.TabIndex = 13;
			this.listBoxISBN.SelectedIndexChanged += new System.EventHandler(this.listBoxISBN_SelectedIndexChanged);
			this.listBoxISBN.Enter += new System.EventHandler(this.listBoxISBN_Enter);
			// 
			// buttonGetAllISBN
			// 
			this.buttonGetAllISBN.Location = new System.Drawing.Point(394, 210);
			this.buttonGetAllISBN.Name = "buttonGetAllISBN";
			this.buttonGetAllISBN.Size = new System.Drawing.Size(75, 41);
			this.buttonGetAllISBN.TabIndex = 14;
			this.buttonGetAllISBN.Text = "&Get All ISBNs";
			this.buttonGetAllISBN.UseVisualStyleBackColor = true;
			this.buttonGetAllISBN.Click += new System.EventHandler(this.buttonGetAllISBN_Click);
			// 
			// labelStatus
			// 
			this.labelStatus.AutoSize = true;
			this.labelStatus.Location = new System.Drawing.Point(10, 267);
			this.labelStatus.MaximumSize = new System.Drawing.Size(472, 0);
			this.labelStatus.MinimumSize = new System.Drawing.Size(472, 0);
			this.labelStatus.Name = "labelStatus";
			this.labelStatus.Size = new System.Drawing.Size(472, 13);
			this.labelStatus.TabIndex = 15;
			this.labelStatus.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// FormLibrary
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(496, 292);
			this.Controls.Add(this.labelStatus);
			this.Controls.Add(this.buttonGetAllISBN);
			this.Controls.Add(this.listBoxISBN);
			this.Controls.Add(this.buttonRemoveBook);
			this.Controls.Add(this.buttonFindBook);
			this.Controls.Add(this.buttonAddBook);
			this.Controls.Add(this.textBoxPubYear);
			this.Controls.Add(this.labelYear);
			this.Controls.Add(this.textBoxRating);
			this.Controls.Add(this.labelRating);
			this.Controls.Add(this.textBoxAuthor);
			this.Controls.Add(this.labelAuthor);
			this.Controls.Add(this.textBoxTitle);
			this.Controls.Add(this.labelTitle);
			this.Controls.Add(this.textBoxISBN);
			this.Controls.Add(this.labelISBN);
			this.Name = "FormLibrary";
			this.Text = "Add/Remove Books";
			this.Load += new System.EventHandler(this.FormLibrary_Load);
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.Label labelISBN;
		private System.Windows.Forms.TextBox textBoxISBN;
		private System.Windows.Forms.TextBox textBoxTitle;
		private System.Windows.Forms.Label labelTitle;
		private System.Windows.Forms.TextBox textBoxAuthor;
		private System.Windows.Forms.Label labelAuthor;
		private System.Windows.Forms.TextBox textBoxRating;
		private System.Windows.Forms.Label labelRating;
		private System.Windows.Forms.TextBox textBoxPubYear;
		private System.Windows.Forms.Label labelYear;
		private System.Windows.Forms.Button buttonAddBook;
		private System.Windows.Forms.Button buttonFindBook;
		private System.Windows.Forms.Button buttonRemoveBook;
		private System.Windows.Forms.ListBox listBoxISBN;
		private System.Windows.Forms.Button buttonGetAllISBN;
		private System.Windows.Forms.Label labelStatus;
	}
}

