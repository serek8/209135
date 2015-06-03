using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Warcaby.Controller;
using Warcaby.Model;
using Warcaby.Properties;

namespace Warcaby
{
    public partial class FormMain : Form
    {
        /// <summary>
        /// Rodzaj nacisniecia myszki
        /// </summary>
        public enum Tap :int { Select = 0, Confirm = 1 };

        Board board;
        PictureBox[,] pawnImage;
        /// <summary>
        /// Po nacisnięciu myszy tutaj zapisuje jej wspolrzedne w zaleznosci od selectOrder
        /// </summary>
        Position selectedPosition;
        /// <summary>
        /// Zawiera kolejnosc klikniecia myszy,  0..1
        /// </summary>
        Tap nextClick;
        public FormMain()
        {
            InitializeComponent();
            board = new Board();
            drawPictureBoxesForPawns();
            selectedPosition = new Position();
            nextClick = Tap.Select;
        }

        private void drawPictureBoxesForPawns()
        {
            #region Add PictureBox for Pawns
            pawnImage = new PictureBox[8, 8];
            for (int y = 0; y < 8; y++)
            {
                for (int x = 0; x < 8; x++)
                {
                    pawnImage[x, y] = new PictureBox();
                    pawnImage[x, y].Location = new Point(board.pawnSize * x, board.pawnSize * y);
                    pawnImage[x, y].Width = board.pawnSize;
                    pawnImage[x, y].Height = board.pawnSize;
                    pawnImage[x, y].Click += new System.EventHandler(this.pictureBoxPawn_Click);
                    pawnImage[x, y].BackColor = Color.Transparent;
                    this.panelBoardBackground.Controls.Add(pawnImage[x, y]);
                }
            }
            #endregion
        }


        /// <summary>
        /// Kazde kliknięcie na bordzie jest odczytywane przez ta metode
        /// bo cały panel jest wypełniony obrazkami 
        /// </summary>
        private void pictureBoxPawn_Click(object sender, EventArgs e)
        {
            Point point = panelBoardBackground.PointToClient(Cursor.Position);
            Position position = getPositionFromMouseCoordinates(point);
            labelPosition.Text = "X:" + position.x.ToString()
                               + "\n"
                               + "Y:"+position.y.ToString();
            // jeżeli zaznaczam
            if (nextClick == Tap.Select && board.isAnyPawnOnPosition(position))
            {
                // zapamietuje pozycje mojego zaznaczenia
                selectedPosition = position;

                enlargePawn(position);
                nextClick = Tap.Confirm;
                return;
            }
            else if (nextClick == Tap.Confirm) // Click.Confirm
            {
                // jezeli potwierdzi sie w białym polu
                if (!board.isPositionAllowed(position))
                {
                    zoomOutPawn(selectedPosition);
                    nextClick = Tap.Select;
                    //MessageBox.Show("biale pole");
                    return;
                }
                zoomOutPawn(selectedPosition);
                //MessageBox.Show( board.move(selectedPosition, position).ToString() );
                board.move(selectedPosition, position);
                nextClick = Tap.Select;
                refreshPawnsLayoutOnBoard();
            }
            
        }

        private void enlargePawn(Position position)
        {
            #region Powiększam pionki gdy są zaznaczone
            if (board.getPawnColourByItsPosition(position) == Pawn.Colours.White)
                pawnImage[position.x, position.y].Image = Resources.whitePawnSelected;
            else pawnImage[position.x, position.y].Image = Resources.blackPawnSelected;
            #endregion
        }
        private void zoomOutPawn(Position position)
        {
            #region Pomniejzam pionki gdy są zaznaczone
            if (board.getPawnColourByItsPosition(position) == Pawn.Colours.White)
                pawnImage[position.x, position.y].Image = Resources.whitePawn;
            else pawnImage[position.x, position.y].Image = Resources.blackPawn;
            #endregion
        }

        #region RightMenu Click
        private void buttonNewGame_Click(object sender, EventArgs e)
        {
            newGame();
        }
        public void newGame()
        {
            board.newGame();
            refreshPawnsLayoutOnBoard();
        }
        #endregion
 
        /// <summary>
        /// Ustawia pionki zgodnie z ich pozycją
        /// </summary>
        public void refreshPawnsLayoutOnBoard()
        {
            clearBoard();
            List<Pawn> pawnList = board.getPawnList();
            //Przeszukuje liste wszystkich Pionków i ustawiam je na bordzie
            foreach (var item in pawnList)
            {
                pawnImage[item.position.x, item.position.y].Visible = true;

                if (item.colour == Pawn.Colours.White)
                    pawnImage[item.position.x, item.position.y].Image = Resources.whitePawn;

                if (item.colour == Pawn.Colours.Black)
                    pawnImage[item.position.x, item.position.y].Image = Resources.blackPawn;
            }
        }

        public void clearBoard()
        {
            for (int y = 0; y < 8; y++)
            {
                for (int x = 0; x < 8; x++)
                {
                    pawnImage[x, y].Image = null;
                }
            }
        }


        public Position getPositionFromMouseCoordinates(Point point)
        {
            Position positonOnBoard = new Position();
            positonOnBoard.x = (int)(point.X / board.pawnSize);
            positonOnBoard.y = (int)(point.Y / board.pawnSize);
            return positonOnBoard;
        }


    }
}
