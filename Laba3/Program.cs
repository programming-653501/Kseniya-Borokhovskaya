using System;


namespace Laba3
{
    // Random KEK
    class Program
    {
        static void rand(out int[,] a, int n)
        {
            a = new int[n, n];
            Random r = new Random();
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    a[i, j] = r.Next(-100, 100);
                }
            // Привет, Ксюша!
            }
        }
        static void output(int[,] a, int n)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    Console.Write($"{a[i, j]}\t");
                    // Тупой комментарий
                }
                Console.WriteLine("\n");
            }
        }
        static void input(out int[,] a, int n)
        {
            Console.WriteLine("Ведите элементы массива ");
            a = new int[n, n];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    while (!int.TryParse(Console.ReadLine(), out a[i, j]) || a[i, j] > 101 || a[i, j] < -101)
                    {
                        Console.WriteLine("Input error");
                    }
                   // a[i, j] = int.Parse(Console.ReadLine());
                }
            }
        }
        static void sort(int[,] a, int n)
        {
            for (int k = 0; k < n; k++)
            {
                for (int i = 0; i < n - 1; i++)
                {
                    // More random KEKS
                    for (int j = 0; j < n - i - 1; j++)
                    {
                        if (a[j, k] > a[j + 1, k])
                        {
                            int temp = a[j, k];
                            // And more KEK
                            a[j, k] = a[j + 1, k];
                            // And once more: KEKE
                            a[j + 1, k] = temp;
                        }
                    }
                }
            }
        }
        // Start doing HERE. Ya Shary
        static void Main(string[] args)
        {
            Console.Write("Введи размерность матрицы: ");
            int n;          
            while (!int.TryParse(Console.ReadLine(), out n) || n <= 0)
            {
                Console.WriteLine("Input error");
            }
            int[,] array = null;// = new int[n, n];
            Console.Write("Задать массив рандомно или вы сами введете значения? \n Нажмите 1, если хотите задать рандомно. \n Нажмите 2, если хотите сами ввести массив. \n");
            int answer;
            while (!int.TryParse(Console.ReadLine(), out answer)  || answer < 0 || answer > 2)
            {
                Console.WriteLine("Input error");
            }
            switch (answer)
            {
                case 1: rand(out array, n);
                    Console.WriteLine("Вот наш массив: ");
                    output(array, n); break;
                case 2: input(out array, n);
                    Console.Write("Введи матрицу(в диапазоне (-100, 100))\n");
                    Console.WriteLine("Вот наш массив: ");
                    output(array, n); break;
                default:  break;
            }
            sort(array, n);
            output(array, n);
            int itemcounter = 0, rowcounter = 0;
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    for (int k = 0; k < n; k++)
                    {
                        if(array[k, i] == array[k, j])
                        {
                            itemcounter++;
                        }
                    }
                    if (itemcounter == n)
                    {
                        rowcounter++;
                    }
                    itemcounter = 0;
                }
            }
            // Демонстрация возможностей админа группы (:
            Console.Write($"Количество похожих пар столбцов: {rowcounter} ");
            Console.ReadKey();
        }
    }
}
