using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Warcaby.Model
{
    public class Pawn
    {
        public enum Colours:int { White = 1, Black = 2 };

        public Colours colour;
        public Position position;
       // public bool isAlive;

        public Pawn(Colours colour, int x, int y)
        {
            this.position = new Position(x, y);
            this.colour = colour;
           // this.isAlive = true;
        }

    }
}
