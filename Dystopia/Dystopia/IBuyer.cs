﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Dystopia
{
    public interface IBuyer
    {
        string Name { get; set; }
        int BuyFood();
        int Food { get; set; }
    }
}
