using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Warcaby.Model;

namespace Warcaby.Controller
{
    public class Board
    {
        public Layout currentLayout;
        public int boardSize;
        public int pawnSize;

        public Board()
        {
            boardSize = 600;
            pawnSize = 600/8; //75
            newGame();
        }

        public void newGame()
        {
            currentLayout = new Layout();
        }

        /// <summary>
        /// Zwraca liste pionków na planszy
        /// </summary>
        public List<Pawn> getPawnList()
        {
            return currentLayout.PawnList;
        }

        public bool move(Position fromPosition, Position toPosition)
        {
            // Jezeli mamy podejsc o jedno pole
            if (fromPosition.x - toPosition.x == 1 || fromPosition.x - toPosition.x == -1)
            {
                if (fromPosition.y - toPosition.y == 1 || fromPosition.y - toPosition.y == -1)
                {
                    return walk(fromPosition, toPosition);
                }
            }
            // Jezeli mamy bić
            else if (fromPosition.x - toPosition.x == 2 || fromPosition.x - toPosition.x == -2)
            {
                if (fromPosition.y - toPosition.y == 2 || fromPosition.y - toPosition.y == -2)
                {
                    return fight(fromPosition, toPosition);
                }
            }



            return false;
        }

        private bool fight(Position fromPosition, Position toPosition)
        {
            Pawn.Colours fromColour = getPawnColourByItsPosition(fromPosition);

            if (fromPosition.x < toPosition.x) // bijemy na prawo
            {
                if (fromPosition.y < toPosition.y) // bijemy na dol
                {
                    if (isAnyPawnOnPosition(new Position(fromPosition.x + 1, fromPosition.y + 1)))
                    {
                        if (getPawnColourByItsPosition(new Position(fromPosition.x + 1, fromPosition.y + 1)) != fromColour) //  pionek bije pionka innego koloru
                        {
                            //usuwam zbitego pionka
                            currentLayout.PawnList.Remove(
                                    currentLayout.PawnList.Find
                                    (pos => pos.position.x == fromPosition.x + 1 &&
                                    pos.position.y == fromPosition.y + 1));
                            //przestawiam zwycieskiego pionka
                            currentLayout.PawnList.Find
                                  (pos => pos.position.x == fromPosition.x &&
                                   pos.position.y == fromPosition.y).position = new Position(toPosition.x, toPosition.y);
                            return true;

                        }
                    }
                }
                else if (fromPosition.y > toPosition.y)// bijemy do gory
                {
                    if (isAnyPawnOnPosition(new Position(fromPosition.x + 1, fromPosition.y - 1)))
                    {
                        if (getPawnColourByItsPosition(new Position(fromPosition.x + 1, fromPosition.y - 1)) != fromColour) //  pionek bije pionka innego koloru
                        {
                            //usuwam zbitego pionka
                            currentLayout.PawnList.Remove(
                            currentLayout.PawnList.Find
                                  (pos => pos.position.x == fromPosition.x + 1 &&
                                   pos.position.y == fromPosition.y - 1));
                            //przestawiam zwycieskiego pionka
                            currentLayout.PawnList.Find
                                  (pos => pos.position.x == fromPosition.x &&
                                   pos.position.y == fromPosition.y).position = new Position(toPosition.x, toPosition.y);
                            return true;

                        }
                    }
                }
            }
            else if (fromPosition.x > toPosition.x) // bije w lewo
            {
                if (fromPosition.y < toPosition.y) // bijemy na dol
                {
                    if (isAnyPawnOnPosition(new Position(fromPosition.x - 1, fromPosition.y + 1)))
                    {
                        if (getPawnColourByItsPosition(new Position(fromPosition.x - 1, fromPosition.y + 1)) != fromColour) // pionek bije pionka innego koloru
                        {
                            //usuwam zbitego pionka
                            currentLayout.PawnList.Remove(
                            currentLayout.PawnList.Find
                                 (pos => pos.position.x == fromPosition.x - 1 &&
                                  pos.position.y == fromPosition.y + 1));

                            currentLayout.PawnList.Find
                                  (pos => pos.position.x == fromPosition.x &&
                                   pos.position.y == fromPosition.y).position = new Position(toPosition.x, toPosition.y);
                            return true;
                        }
                    }
                }
                else if (fromPosition.y > toPosition.y) // bijemy na gore
                {
                    if (isAnyPawnOnPosition(new Position(fromPosition.x - 1, fromPosition.y - 1)))
                    {
                        if (getPawnColourByItsPosition(new Position(fromPosition.x - 1, fromPosition.y - 1)) != fromColour) // pionek bije pionka innego koloru
                        {
                            //usuwam zbitego pionka
                            currentLayout.PawnList.Remove(
                            currentLayout.PawnList.Find
                                 (pos => pos.position.x == fromPosition.x - 1 &&
                                  pos.position.y == fromPosition.y - 1));

                            currentLayout.PawnList.Find
                                  (pos => pos.position.x == fromPosition.x &&
                                   pos.position.y == fromPosition.y).position = new Position(toPosition.x, toPosition.y);
                            return true;
                        }
                    }
                }
            }


            return false;
        }
        /// <summary>
        /// Metoda odpowiada za ruch pionka o jedno pole
        /// </summary>
        /// <param name="fromPosition"></param>
        /// <param name="toPosition"></param>
        /// <returns></returns>
        private bool walk(Position fromPosition, Position toPosition)
        {
            Pawn.Colours colour = getPawnColourByItsPosition(fromPosition);

            if (colour == Pawn.Colours.White)
                if (fromPosition.y < toPosition.y) return false;

            if (colour == Pawn.Colours.Black)
                if (fromPosition.y > toPosition.y) return false;

            if (isAnyPawnOnPosition(toPosition)) return false;


            currentLayout.PawnList.Find
                (pos => pos.position.x == fromPosition.x &&
                        pos.position.y == fromPosition.y).position
                      = new Position(toPosition.x, toPosition.y);
            return true;
        }

        /// <summary>
        /// Pobiera kolor pionka z danej pozycji
        /// </summary>
        public Pawn.Colours getPawnColourByItsPosition(Position position)
        {
            return (from c in currentLayout.PawnList
                    where c.position.x == position.x
                    where c.position.y == position.y
                    select c.colour).ToList().First();
        }

        /// <summary>
        /// Sprawdza czy na danej pozycji jest jakis pionek
        /// </summary>
        public bool isAnyPawnOnPosition(Position position)
        {
            var query = ((from c in currentLayout.PawnList
                          where c.position.x == position.x && c.position.y == position.y
                          select c).ToList());
            if(query.Count == 0) return false;
            return true;
        }

        /// <summary>
        /// Sprawdza czy pole jest białe (na bialych nic nie moze stac)
        /// </summary>
        public bool isPositionAllowed(Position position)
        {
            if ((position.x + position.y) % 2 == 1) return true;

            return false;
        }

    }
}
