using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Warcaby.Model
{
    public class Layout
    {
        public int id;
        List<Pawn> pawnList;
        Pawn.Colours colourTurn;

        public Layout()
        {
            id = 0;
            pawnList = new List<Pawn>();
            colourTurn = Pawn.Colours.White;
            setDefaultLayout();
        }

        /// <summary>
        /// Dodaje pionki do pawnList
        /// </summary>
        public void setDefaultLayout()
        {
            pawnList.Clear();

            //Wypelniam bialymi pionkami od dołu
            pawnList.Add(new Pawn(Pawn.Colours.White, 0, 7));
            pawnList.Add(new Pawn(Pawn.Colours.White, 2, 7));
            pawnList.Add(new Pawn(Pawn.Colours.White, 4, 7));
            pawnList.Add(new Pawn(Pawn.Colours.White, 6, 7));

            pawnList.Add(new Pawn(Pawn.Colours.White, 1, 6));
            pawnList.Add(new Pawn(Pawn.Colours.White, 3, 6));
            pawnList.Add(new Pawn(Pawn.Colours.White, 5, 6));
            pawnList.Add(new Pawn(Pawn.Colours.White, 7, 6));

            pawnList.Add(new Pawn(Pawn.Colours.White, 0, 5));
            pawnList.Add(new Pawn(Pawn.Colours.White, 2, 5));
            pawnList.Add(new Pawn(Pawn.Colours.White, 4, 5));
            pawnList.Add(new Pawn(Pawn.Colours.White, 6, 5));

            //Wypelniam czarnymi pionkami od dołu
            pawnList.Add(new Pawn(Pawn.Colours.Black, 1, 0));
            pawnList.Add(new Pawn(Pawn.Colours.Black, 3, 0));
            pawnList.Add(new Pawn(Pawn.Colours.Black, 5, 0));
            pawnList.Add(new Pawn(Pawn.Colours.Black, 7, 0));

            pawnList.Add(new Pawn(Pawn.Colours.Black, 0, 1));
            pawnList.Add(new Pawn(Pawn.Colours.Black, 2, 1));
            pawnList.Add(new Pawn(Pawn.Colours.Black, 4, 1));
            pawnList.Add(new Pawn(Pawn.Colours.Black, 6, 1));

            pawnList.Add(new Pawn(Pawn.Colours.Black, 1, 2));
            pawnList.Add(new Pawn(Pawn.Colours.Black, 3, 2));
            pawnList.Add(new Pawn(Pawn.Colours.Black, 5, 2));
            pawnList.Add(new Pawn(Pawn.Colours.Black, 7, 2));
        }

        public List<Pawn> PawnList
        {
            get { return pawnList; }
        }


    }
}
