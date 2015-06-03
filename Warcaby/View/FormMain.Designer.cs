namespace Warcaby
{
    partial class FormMain
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
            if (disposing && (components != null))
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
            this.buttonNewGame = new System.Windows.Forms.Button();
            this.panelBoardBackground = new System.Windows.Forms.Panel();
            this.labelPosition = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // buttonNewGame
            // 
            this.buttonNewGame.Location = new System.Drawing.Point(634, 12);
            this.buttonNewGame.Name = "buttonNewGame";
            this.buttonNewGame.Size = new System.Drawing.Size(108, 33);
            this.buttonNewGame.TabIndex = 1;
            this.buttonNewGame.Text = "Nowa Gra";
            this.buttonNewGame.UseVisualStyleBackColor = true;
            this.buttonNewGame.Click += new System.EventHandler(this.buttonNewGame_Click);
            // 
            // panelBoardBackground
            // 
            this.panelBoardBackground.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left)));
            this.panelBoardBackground.BackgroundImage = global::Warcaby.Properties.Resources.chessboard;
            this.panelBoardBackground.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.panelBoardBackground.Location = new System.Drawing.Point(0, 0);
            this.panelBoardBackground.Name = "panelBoardBackground";
            this.panelBoardBackground.Size = new System.Drawing.Size(600, 600);
            this.panelBoardBackground.TabIndex = 0;
            // 
            // labelPosition
            // 
            this.labelPosition.AutoSize = true;
            this.labelPosition.Location = new System.Drawing.Point(631, 531);
            this.labelPosition.Name = "labelPosition";
            this.labelPosition.Size = new System.Drawing.Size(43, 13);
            this.labelPosition.TabIndex = 2;
            this.labelPosition.Text = "pozycja";
            // 
            // FormMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(820, 600);
            this.Controls.Add(this.labelPosition);
            this.Controls.Add(this.buttonNewGame);
            this.Controls.Add(this.panelBoardBackground);
            this.Name = "FormMain";
            this.Text = "Warcaby";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel panelBoardBackground;
        private System.Windows.Forms.Button buttonNewGame;
        private System.Windows.Forms.Label labelPosition;
    }
}

