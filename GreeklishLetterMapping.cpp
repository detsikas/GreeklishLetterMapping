//
//  GreeklishLetterMapping.cpp
//  Greeklish
//
//  Created by Nikos Detsikas on 14/6/15.
//  Copyright (c) 2015 Nikos Detsikas. All rights reserved.
//

#include "GreeklishLetterMapping.h"

using namespace Greeklish;

GreeklishLetterMapping::GreeklishLetterMapping()
{
    letterMap[utf8letter(0xce,0x91)] = "A"; //A
    letterMap[utf8letter(0xce,0x92)] = "B"; //B
    letterMap[utf8letter(0xce,0x93)] = "G"; //Γ
    letterMap[utf8letter(0xce,0x94)] = "D"; //Δ
    letterMap[utf8letter(0xce,0x95)] = "E"; //Ε
    letterMap[utf8letter(0xce,0x96)] = "Z"; //Ζ
    letterMap[utf8letter(0xce,0x97)] = "H"; //Η
    letterMap[utf8letter(0xce,0x98)] = "Th"; //Θ
    letterMap[utf8letter(0xce,0x99)] = "I"; //Ι
    letterMap[utf8letter(0xce,0x9a)] = "K"; //Κ
    letterMap[utf8letter(0xce,0x9b)] = "L"; //Λ
    letterMap[utf8letter(0xce,0x9c)] = "M"; //Μ
    letterMap[utf8letter(0xce,0x9d)] = "N"; //Ν
    letterMap[utf8letter(0xce,0x9e)] = "Ks"; //Ξ
    letterMap[utf8letter(0xce,0x9f)] = "O"; //Ο
    letterMap[utf8letter(0xce,0xa0)] = "P"; //Π
    letterMap[utf8letter(0xce,0xa1)] = "R"; //Ρ
    letterMap[utf8letter(0xce,0xa3)] = "S"; //Σ
    letterMap[utf8letter(0xce,0xa4)] = "T"; //Τ
    letterMap[utf8letter(0xce,0xa5)] = "Y"; //Υ
    letterMap[utf8letter(0xce,0xa6)] = "F"; //Φ
    letterMap[utf8letter(0xce,0xa7)] = "X"; //Χ
    letterMap[utf8letter(0xce,0xa8)] = "Ps"; //Ψ
    letterMap[utf8letter(0xce,0xa9)] = "W"; //Ω
    
    letterMap[utf8letter(0xce,0xb1)] = "a"; //α
    letterMap[utf8letter(0xce,0xb2)] = "b"; //β
    letterMap[utf8letter(0xce,0xb3)] = "g"; //γ
    letterMap[utf8letter(0xce,0xb4)] = "d"; //δ
    letterMap[utf8letter(0xce,0xb5)] = "e"; //ε
    letterMap[utf8letter(0xce,0xb6)] = "z"; //ζ
    letterMap[utf8letter(0xce,0xb7)] = "h"; //η
    letterMap[utf8letter(0xce,0xb8)] = "th"; //θ
    letterMap[utf8letter(0xce,0xb9)] = "i"; //ι
    letterMap[utf8letter(0xce,0xba)] = "k"; //κ
    letterMap[utf8letter(0xce,0xbb)] = "l"; //λ
    letterMap[utf8letter(0xce,0xbc)] = "m"; //μ
    letterMap[utf8letter(0xce,0xbd)] = "n"; //ν
    letterMap[utf8letter(0xce,0xbe)] = "ks"; //ξ
    letterMap[utf8letter(0xce,0xbf)] = "o"; //ο
    letterMap[utf8letter(0xcf,0x80)] = "p"; //π
    letterMap[utf8letter(0xcf,0x81)] = "r"; //ρ
    letterMap[utf8letter(0xcf,0x83)] = "s"; //σ
    letterMap[utf8letter(0xcf,0x84)] = "t"; //τ
    letterMap[utf8letter(0xcf,0x85)] = "y"; //υ
    letterMap[utf8letter(0xcf,0x86)] = "f"; //φ
    letterMap[utf8letter(0xcf,0x87)] = "x"; //χ
    letterMap[utf8letter(0xcf,0x88)] = "ps"; //ψ
    letterMap[utf8letter(0xcf,0x89)] = "w"; //ω
    letterMap[utf8letter(0xcf,0x82)] = "s"; //ς
    
    letterMap[utf8letter(0xce,0x86)] = "A"; //Ά
    letterMap[utf8letter(0xce,0x88)] = "E"; //Έ
    letterMap[utf8letter(0xce,0x89)] = "H"; //Ή
    letterMap[utf8letter(0xce,0x8a)] = "I"; //Ί
    letterMap[utf8letter(0xce,0x8c)] = "O"; //Ό
    letterMap[utf8letter(0xce,0x8e)] = "Y"; //Υ
    letterMap[utf8letter(0xce,0x8f)] = "W"; //Ώ
    
    letterMap[utf8letter(0xce,0xac)] = "a"; //ά
    letterMap[utf8letter(0xce,0xad)] = "e"; //έ
    letterMap[utf8letter(0xce,0xae)] = "h"; //ή
    letterMap[utf8letter(0xce,0xaf)] = "i"; //ί
    letterMap[utf8letter(0xcf,0x8c)] = "o"; //ό
    letterMap[utf8letter(0xcf,0x8d)] = "y"; //ύ
    letterMap[utf8letter(0xcf,0x8e)] = "w"; //ώ

    letterMap[utf8letter(0xce,0xaa)] = "I"; //Ϊ
    letterMap[utf8letter(0xce,0xab)] = "Y"; //Ϋ

    letterMap[utf8letter(0xcf,0x8a)] = "i"; //ϊ
    letterMap[utf8letter(0xcf,0x8b)] = "y"; //ϋ
    
    letterMap[utf8letter(0xce,0xb0)] = "y"; //ΰ
    letterMap[utf8letter(0xce,0x90)] = "i"; //ΐ
}

string GreeklishLetterMapping::convertToGreeklish(string const & greekPhrase)
{
    string greeklishPhrase;
    unsigned char bufferedLetter = 0;
    for (string::const_iterator it=greekPhrase.begin(); it!=greekPhrase.end(); it++)
    {
        if (((unsigned char)(*it)==0xce) || ((unsigned char)(*it)==0xcf))
        {
            bufferedLetter = *it;
        }
        else if (bufferedLetter)
        {
            greeklishPhrase+=letterMap[utf8letter(bufferedLetter, (unsigned char)*it)];
            bufferedLetter = 0;
        }
        else
        {
            greeklishPhrase+=(*it);
        }
    }
    return greeklishPhrase;
}