using System;

namespace ConsoleApplication3
{
    class Matriculant                //Абитуриент
    {
        public int ID;
        public string speciality;
        string FIO, passport_info, city;
        int first_mark, second_mark, third_mark;
        int grade_score, number_of_school, total_score;
        bool Student = false;
        
        public void add (int i)             //Подача заявления
        {
            ID = i++;
            Console.WriteLine("Choose faculty:");
            Console.WriteLine("1.Faculty of computer design");
            Console.WriteLine("2.Faculty of computer systems and networks");
            Console.WriteLine("3.Faculty of informatics technologies and managment");

            bool exit = true;
            do
            {
                var choice = Console.ReadKey();
                switch (choice.Key)
                {
                    case ConsoleKey.D1:
                        {
                            Console.Clear();
                            Console.WriteLine("Choose speciality:");
                            Console.WriteLine("1.ME");
                            Console.WriteLine("2.PMEN");
                            Console.WriteLine("3.PMS");
                            var choice_1 = Console.ReadKey();
                            switch (choice_1.Key)
                            {
                                case ConsoleKey.D1:
                                    {
                                        speciality = "ME";
                                        exit = false;
                                        break;
                                    }

                                case ConsoleKey.D2:
                                    {
                                        speciality = "PMEN";
                                        exit = false;
                                        break;


                                    }
                                case ConsoleKey.D3:
                                    {
                                        speciality = "PMS";
                                        exit = false;
                                        break;
                                    }
                                default:
                                    {
                                        break;
                                    }

                            }
                            break;
                        }

                    case ConsoleKey.D2:
                        {
                            Console.Clear();
                            Console.WriteLine("Choose speciality:");
                            Console.WriteLine("1.CMSN");
                            Console.WriteLine("2.SIT");
                            Console.WriteLine("3.ITP");
                            var choice_2 = Console.ReadKey();
                            switch (choice_2.Key)
                            {
                                case ConsoleKey.D1:
                                    {
                                        speciality = "CMSN";
                                        exit = false;
                                        break;
                                    }

                                case ConsoleKey.D2:
                                    {
                                        speciality = "SIT";
                                        exit = false;
                                        break;


                                    }
                                case ConsoleKey.D3:
                                    {
                                        speciality = "ITP";
                                        exit = false;
                                        break;
                                    }
                                default:
                                    {
                                        break;
                                    }

                            }
                            break;


                        }
                    case ConsoleKey.D3:
                        {
                            Console.Clear();
                            Console.WriteLine("Choose speciality:");
                            Console.WriteLine("1.ASPI");
                            Console.WriteLine("2.AI");
                            Console.WriteLine("3.ITM");
                            var choice_3 = Console.ReadKey();
                            switch (choice_3.Key)
                            {
                                case ConsoleKey.D1:
                                    {
                                        speciality = "ASPI";
                                        exit = false;
                                        break;
                                    }

                                case ConsoleKey.D2:
                                    {
                                        speciality = "AI";
                                        exit = false;
                                        break;
                                    }
                                case ConsoleKey.D3:
                                    {
                                        speciality = "ITM";
                                        exit = false;
                                        break;
                                    }
                                default:
                                    {
                                        break;
                                    }

                            }
                            break;
                        }
                    default:
                        {
                            Console.Clear();
                            Console.WriteLine("Choose faculty:");
                            Console.WriteLine("1.Faculty of computer design");
                            Console.WriteLine("2.Faculty of computer systems and networks");
                            Console.WriteLine("3.Faculty of informatics technologies and managment");
                            break;
                        }

                }
            } while (exit);
            
            Console.Clear();
            Console.WriteLine("Enter your FIO: ");
            FIO = Console.ReadLine();
            Console.WriteLine("Enter first mark: ");
            first_mark = checking();
            
            Console.WriteLine("Enter second mark: ");
            second_mark = checking();
            Console.WriteLine("Enter third mark: ");
            third_mark = checking();
            Console.WriteLine("Enter your grade score: ");
            grade_score = checking();

            total_score = first_mark + second_mark + third_mark + grade_score;

            Console.WriteLine("Enter your passport serial number: ");
            passport_info = Console.ReadLine();
            Console.WriteLine("Enter your city: ");
            city = Console.ReadLine();
            Console.WriteLine("Enter your number of school: ");
            do
            {
                try
                {
                    number_of_school = int.Parse(Console.ReadLine());
                }
                catch (FormatException)
                {
                    Console.WriteLine("Invalid input!");
                    number_of_school = 0;
                }
            } while (number_of_school == 0);
        }

        public void show()                          //Вывод абитуриентов/студентов
        {
            Console.WriteLine(ID.ToString() + ":");

            Console.WriteLine("Speciality: " + speciality);

            Console.WriteLine("FIO: " + FIO);

            Console.WriteLine("First mark: " + first_mark.ToString());

            Console.WriteLine("Second mark: " + second_mark.ToString());

            Console.WriteLine("Third mark: " + third_mark.ToString());

            Console.WriteLine("Grade score: " + grade_score.ToString());

            Console.WriteLine("Total score: " + total_score.ToString());

            Console.WriteLine("Passport serial number: " + passport_info);
           
            Console.WriteLine("City: " + city);
            
            Console.WriteLine("Number of school: " + number_of_school.ToString());
            Console.WriteLine();           
        }

        public static void Show_students(Matriculant[] abitur, int Length)   //Выбор специальности для вывода студентов
        {
            Console.WriteLine("Choose faculty:");
            Console.WriteLine("1.Faculty of computer design");
            Console.WriteLine("2.Faculty of computer systems and networks");
            Console.WriteLine("3.Faculty of informatics technologies and managment");

            bool exit = true;
            do
            {
                var choice = Console.ReadKey();
                switch (choice.Key)
                {
                    case ConsoleKey.D1:
                        {
                            Console.Clear();
                            Console.WriteLine("Choose speciality:");
                            Console.WriteLine("1.ME");
                            Console.WriteLine("2.PMEN");
                            Console.WriteLine("3.PMS");
                            var choice_1 = Console.ReadKey();
                            switch (choice_1.Key)
                            {
                                case ConsoleKey.D1:
                                    {
                                        check_abitur(abitur, Length, "ME");
                                        exit = false;
                                        break;
                                    }

                                case ConsoleKey.D2:
                                    {
                                        check_abitur(abitur, Length, "PMEN");
                                        exit = false;
                                        break;


                                    }
                                case ConsoleKey.D3:
                                    {
                                        check_abitur(abitur, Length, "PMS");
                                        exit = false;
                                        break;
                                    }
                                default:
                                    {
                                        break;
                                    }

                            }
                            break;
                        }

                    case ConsoleKey.D2:
                        {
                            Console.Clear();
                            Console.WriteLine("Choose speciality:");
                            Console.WriteLine("1.CMSN");
                            Console.WriteLine("2.SIT");
                            Console.WriteLine("3.ITP");
                            var choice_2 = Console.ReadKey();
                            switch (choice_2.Key)
                            {
                                case ConsoleKey.D1:
                                    {
                                        check_abitur(abitur, Length, "CMSN");
                                        exit = false;
                                        break;
                                    }

                                case ConsoleKey.D2:
                                    {
                                        check_abitur(abitur, Length, "SIT");
                                        exit = false;
                                        break;


                                    }
                                case ConsoleKey.D3:
                                    {
                                        check_abitur(abitur, Length, "ITP");
                                        exit = false;
                                        break;
                                    }
                                default:
                                    {
                                        break;
                                    }

                            }
                            break;


                        }
                    case ConsoleKey.D3:
                        {
                            Console.Clear();
                            Console.WriteLine("Choose speciality:");
                            Console.WriteLine("1.ASPI");
                            Console.WriteLine("2.AI");
                            Console.WriteLine("3.ITM");
                            var choice_3 = Console.ReadKey();
                            switch (choice_3.Key)
                            {
                                case ConsoleKey.D1:
                                    {
                                        check_abitur(abitur, Length, "ASPI");
                                        exit = false;
                                        break;
                                    }

                                case ConsoleKey.D2:
                                    {
                                        check_abitur(abitur, Length, "AI");
                                        exit = false;
                                        break;
                                    }
                                case ConsoleKey.D3:
                                    {
                                        check_abitur(abitur, Length, "ITM");
                                        exit = false;
                                        break;
                                    }
                                default:
                                    {
                                        break;
                                    }

                            }
                            break;
                        }
                    default:
                        {
                            Console.Clear();
                            Console.WriteLine("Choose faculty:");
                            Console.WriteLine("1.Faculty of computer design");
                            Console.WriteLine("2.Faculty of computer systems and networks");
                            Console.WriteLine("3.Faculty of informatics technologies and managment");
                            break;
                        }

                }
            } while (exit);
        }

        public static void check_abitur(Matriculant[] abitur, int Length, string spec)     //Проверка на студента
        {
            for (int i = 0; i < Length; i++)
            {
                if (abitur[i].speciality == spec && abitur[i].Student == true)
                    abitur[i].show(); 
            }
        }

        public int checking()                //Проверка ввода
        {
            int Value;
            do
            {
                try
                {
                    Value = int.Parse(Console.ReadLine());
                    if (Value < 6 || Value > 100)
                        throw new FormatException();
                }
                catch (FormatException)
                {
                    Console.WriteLine("Invalid input!");
                    Value = 0;
                }
            } while (Value == 0);
            return Value;
        }

        public static void Rating_sort(Matriculant[] abitur, int Length)       //Сортировка абитуриентов
        {
            if (abitur[0] == null)
            {
                Console.WriteLine("Your list is empty!");
                return;
            }    
            for (int i = 0; i < Length; i++)
            {
                for (int j = 0; j < Length - i - 1; j++)
                {
                    if (abitur[j].total_score < abitur[j + 1].total_score)
                    {
                        Matriculant temp = abitur[j];
                        int temp_id = abitur[j].ID;
                        abitur[j].ID = abitur[j + 1].ID;
                        abitur[j] = abitur[j + 1];
                        abitur[j + 1].ID = temp_id;
                        abitur[j + 1] = temp;
                    }
                }
            }
        }
                                 //Зачисление по баллу при кол-ве заявок больше, чем мест
        public static void Enroll_by_score(Matriculant[] abitur, int Length, string spec)
        {
            int free_places = 5;
            for (int i = 0; i < Length; i++)
            {
                if (free_places == 0)
                    break;
                if (abitur[i].speciality == spec)
                {
                    abitur[i].Student = true;
                    free_places--;
                }                
            }
        }
                               //Зачисление по баллу при кол-ве заявок меньше, чем мест
        public static void Enroll_all(Matriculant[] abitur, int Length, string spec)
        {
            for (int i = 0; i < Length; i++)
            {
                if (abitur[i].speciality == spec)
                    abitur[i].Student = true;
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            int i = 0;
            Matriculant[] abitur = new Matriculant[255]; //Инициализация
            int[] speciality_count = new int[9];
            int[] speciality_places = new int[9];
            string[] speciality = new string[] { "ME", "PMEN", "PMS", "CMSN", "SIT", "ITP", "ASPI", "AI", "ITM" };
            for (int j = 0; j < 9; j++)
            {
                speciality_count[j] = 0;
                speciality_places[j] = 5;  //Кол-во бюджетных мест(можно изменить)
            }           

            for (int exit = 0; exit != 1;)
            {
                Console.Clear();
                Console.WriteLine("=========================");
                Console.WriteLine("Database of matriculants:");
                Console.WriteLine("=========================");
                Console.WriteLine("1.Add Matriculant");
                Console.WriteLine("2.Rating of matriculants");           //Главное МЕНЮ
                Console.WriteLine("3.Withdraw aplication");
                Console.WriteLine("4.Enroll matriculants");
                Console.WriteLine("5.List of students");
                Console.WriteLine("6.Exit");
                var choice = Console.ReadKey();
                switch (choice.Key)
                {
                    case ConsoleKey.D1:
                        {
                            Console.Clear();
                            Console.WriteLine("===============");
                            Console.WriteLine("Add matriculant");
                            Console.WriteLine("===============");
                            Console.WriteLine();
                            abitur[i] = new Matriculant();


                            abitur[i].add(i);

                        
                            i++;

                            break;
                        }

                    case ConsoleKey.D2:
                        {

                            Console.Clear();
                            Console.WriteLine("======================");
                            Console.WriteLine("Rating of matriculants");
                            Console.WriteLine("======================");
                            Console.WriteLine();
                            Matriculant.Rating_sort(abitur, i);
                            for (int j = 0; j < i; j++)
                            {
                                abitur[j].show();
                            }
                            Console.WriteLine("Click any button...");
                            Console.ReadKey();
                            break;


                        }
                    case ConsoleKey.D3:
                        {
                            Console.Clear();
                            Console.WriteLine("==================");
                            Console.WriteLine("Delete matriculant");
                            Console.WriteLine("==================");
                            Console.WriteLine();
                            for (int j = 0; j < i; j++)
                            {
                                Console.WriteLine("Matriculant №" + (j + 1));
                                abitur[j].show();
                            }
                            Console.WriteLine("\nChoose № of matriculant: ");
                            int number = 0;
                            do
                            {
                                try
                                {
                                    number = int.Parse(Console.ReadLine());
                                    if (number > i + 1)
                                    {
                                        Console.WriteLine("There are only " + i + " matriculants!");
                                        number = 0;
                                    }
                                }
                                catch (FormatException)
                                {
                                    Console.WriteLine("Invalid input!");

                                }
                            } while (number == 0);

                            for (int j = number - 1; j < i; j++)       //Удаление заявки
                            {
                                if (j == i - 1)
                                {
                                    abitur[j] = null;
                                    i--;
                                    break;
                                }
                                abitur[j] = abitur[j + 1];
                                abitur[j].ID--;
                            }

                            Console.WriteLine("Click any button... ");
                            Console.ReadKey();
                            break;
                        }

                    case ConsoleKey.D4:
                        {
                            Console.Clear();
                            Matriculant.Rating_sort(abitur, i);
                            for (int j = 0; j < i; j++)
                            {
                                for(int count = 0; count < 9; count++)
                                {
                                    if (abitur[j].speciality == speciality[count])
                                        speciality_count[count]++;                                  
                                }



                            }

                            for (int count = 0; count < 9; count++)
                            {
                                if (speciality_count[count] > speciality_places[count])
                                    Matriculant.Enroll_by_score(abitur, i, speciality[count]);
                                else
                                    Matriculant.Enroll_all(abitur, i, speciality[count]);
                            }

                            Console.WriteLine("Enroll is over");
                            Console.WriteLine("Click any button... ");
                            Console.ReadKey();
                            break;
                        }
                    case ConsoleKey.D5:
                        {
                            Console.Clear();
                            /* Console.WriteLine("======================");
                             Console.WriteLine("List of students");
                             Console.WriteLine("======================");
                             Console.WriteLine();*/
                            Matriculant.Show_students(abitur, i);
                            Console.WriteLine("Click any button...");
                            Console.ReadKey();
                            break;
                        }
                    case ConsoleKey.D6:
                        {
                            exit = 1;
                            break;
                        }
                    default:
                        {
                            break;
                        }

                }


            }
        }
    }
}
