namespace PROG210LastHW
{
	partial class Form1
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
			this.dataGridViewAccount = new System.Windows.Forms.DataGridView();
			this.dataGridViewProduct = new System.Windows.Forms.DataGridView();
			this.labelBuy = new System.Windows.Forms.Label();
			this.buttonBuy = new System.Windows.Forms.Button();
			this.labelStatus = new System.Windows.Forms.Label();
			((System.ComponentModel.ISupportInitialize)(this.dataGridViewAccount)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.dataGridViewProduct)).BeginInit();
			this.SuspendLayout();
			// 
			// dataGridViewAccount
			// 
			this.dataGridViewAccount.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
			this.dataGridViewAccount.Location = new System.Drawing.Point(12, 12);
			this.dataGridViewAccount.Name = "dataGridViewAccount";
			this.dataGridViewAccount.RowHeadersWidth = 21;
			this.dataGridViewAccount.Size = new System.Drawing.Size(444, 150);
			this.dataGridViewAccount.TabIndex = 0;
			this.dataGridViewAccount.SelectionChanged += new System.EventHandler(this.setBuyButton);
			this.dataGridViewAccount.DoubleClick += new System.EventHandler(this.Form1_Load);
			// 
			// dataGridViewProduct
			// 
			this.dataGridViewProduct.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
			this.dataGridViewProduct.Location = new System.Drawing.Point(12, 199);
			this.dataGridViewProduct.Name = "dataGridViewProduct";
			this.dataGridViewProduct.RowHeadersWidth = 21;
			this.dataGridViewProduct.Size = new System.Drawing.Size(444, 150);
			this.dataGridViewProduct.TabIndex = 1;
			this.dataGridViewProduct.SelectionChanged += new System.EventHandler(this.setBuyButton);
			this.dataGridViewProduct.DoubleClick += new System.EventHandler(this.Form1_Load);
			// 
			// labelBuy
			// 
			this.labelBuy.AutoSize = true;
			this.labelBuy.Location = new System.Drawing.Point(13, 369);
			this.labelBuy.Name = "labelBuy";
			this.labelBuy.Size = new System.Drawing.Size(224, 13);
			this.labelBuy.TabIndex = 2;
			this.labelBuy.Text = "Select Customer, select product and click Buy";
			// 
			// buttonBuy
			// 
			this.buttonBuy.Location = new System.Drawing.Point(297, 369);
			this.buttonBuy.Name = "buttonBuy";
			this.buttonBuy.Size = new System.Drawing.Size(75, 23);
			this.buttonBuy.TabIndex = 3;
			this.buttonBuy.Text = "Buy";
			this.buttonBuy.UseVisualStyleBackColor = true;
			this.buttonBuy.Click += new System.EventHandler(this.buttonBuy_Click);
			// 
			// labelStatus
			// 
			this.labelStatus.AutoSize = true;
			this.labelStatus.Location = new System.Drawing.Point(16, 432);
			this.labelStatus.Name = "labelStatus";
			this.labelStatus.Size = new System.Drawing.Size(90, 13);
			this.labelStatus.TabIndex = 4;
			this.labelStatus.Text = "No purchases yet";
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(468, 517);
			this.Controls.Add(this.labelStatus);
			this.Controls.Add(this.buttonBuy);
			this.Controls.Add(this.labelBuy);
			this.Controls.Add(this.dataGridViewProduct);
			this.Controls.Add(this.dataGridViewAccount);
			this.Name = "Form1";
			this.Text = "Product Order Form";
			this.Load += new System.EventHandler(this.Form1_Load);
			this.DoubleClick += new System.EventHandler(this.Form1_Load);
			((System.ComponentModel.ISupportInitialize)(this.dataGridViewAccount)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.dataGridViewProduct)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.DataGridView dataGridViewAccount;
		private System.Windows.Forms.DataGridView dataGridViewProduct;
		private System.Windows.Forms.Label labelBuy;
		private System.Windows.Forms.Button buttonBuy;
		private System.Windows.Forms.Label labelStatus;
	}
}

