//
//  LetterMapping.h
//  Greeklish
//
//  Created by Nikos Detsikas on 14/6/15.
//  Copyright (c) 2015 Nikos Detsikas. All rights reserved.
//

#ifndef __Greeklish__LetterMapping__
#define __Greeklish__LetterMapping__

#include <stdio.h>
#include <string>
#include <map>

using namespace std;

namespace Greeklish
{
    typedef pair<unsigned char, unsigned char> utf8letter;
    typedef map<utf8letter, string> LetterMap;

    class GreeklishLetterMapping
    {
    public:
        GreeklishLetterMapping();
        string convertToGreeklish(string const &);
    private:
        LetterMap letterMap;
    };
}

#endif /* defined(__Greeklish__LetterMapping__) */
