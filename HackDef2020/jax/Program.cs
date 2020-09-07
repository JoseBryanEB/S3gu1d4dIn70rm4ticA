using System;
using System.IO;

namespace ConsoleApp1
{
    class Program
    {   
        static void Main(string[] args)
        {
            Exception x=null;
            string _f = "Personal";
            /// Console.WriteLine("Hello World!");
            Console.WriteLine( new Flag(_f).print());
            
        }
        
    }
    class Flag
    {
        // Token: 0x06000001 RID: 1 RVA: 0x00002050 File Offset: 0x00000250
        public Flag(string _f)
        {
            try
            {
                File.ReadAllText(_f.ToCharArray()[8].ToString());
                this.s = "hackdf{NOP_ESTO_NO_ES_LO_QUE_BUSCAS!}";
            }
            catch (Exception e)
            {
                this.l(new IndexOutOfRangeException(), _f);
            }
        }

        // Token: 0x06000002 RID: 2 RVA: 0x000020A4 File Offset: 0x000002A4
        private void l(Exception e, string _f)
        {
            string message = e.Message;
            this.s = "";
            Console.WriteLine(this.s);
            if (e.GetType() == typeof(IndexOutOfRangeException))
            {
                string text = this.f(_f);
                long num = 137438953472L;
                int[] array = new int[]
                {
                    -47,
                    -86,
                    -107,
                    -101,
                    -83,
                    -41,
                    -80,
                    -82,
                    13,
                    9,
                    -22,
                    -82,
                    -68,
                    -81,
                    -91,
                    -49,
                    -80,
                    -80,
                    -71,
                    -87,
                    -30,
                    0,
                    -36,
                    -97,
                    -12,
                    -61,
                    -101,
                    -67,
                    -94,
                    -75,
                    -26,
                    -15
                };
                char[] array2 = message.ToCharArray();
                char[] array3 = text.ToCharArray();
                while (((long)this.s.Length & num) == 0L)
                {
                    byte b = Convert.ToByte(array2[this.s.Length]);
                    b ^= (byte)((int)Convert.ToByte(array3[this.s.Length % 8]) + array[this.s.Length]);
                    this.s += Convert.ToChar(b).ToString();
                    num >>= 1;
                }
                return;
            }
            Console.WriteLine("Nop, esa no es la excepcion correcta");
        }

        // Token: 0x06000003 RID: 3 RVA: 0x0000219E File Offset: 0x0000039E
        public string print()
        {
            return this.s;
        }

        // Token: 0x06000004 RID: 4 RVA: 0x000021A6 File Offset: 0x000003A6
        private string f(string inp)
        {
            if ((inp.Length & 8) <= 0)
            {
                return this.f(inp + "x");
            }
            return inp;
        }

        // Token: 0x04000001 RID: 1
        private string s;
    }
}
