//============================================================================
// Name        : Bulgarian.cpp
// Author      : Sean Robert McGuffee
// Description : Hello World in C++
//============================================================================
#include <codecvt>
#include <iostream>
#include <iomanip>

int main()
{

    std::locale::global( std::locale( std::locale( "en_US.UTF-8" ), new std::codecvt_utf8 < wchar_t > ) );

    std::wcin.imbue( std::locale( ) );
    std::wcout.imbue( std::locale( ) );
    std::wcerr.imbue( std::locale( ) );

    std::wcout << L'Ж' << std::endl;
    //              0123456789012345678901234567890123456789
    std::wcout << L"English      Decimal   Hex       Oct       " << std::endl;
    std::wstring EnglishUpper;
    std::wstring EnglishLower;
    for( unsigned int letterIndex = 0; letterIndex < 58; letterIndex++ )
    {
        wchar_t EnglishLetter = ( ( ( wchar_t ) L'A' ) + letterIndex );
        if( isalpha( EnglishLetter ) )
        {
            if( isupper( EnglishLetter ) )
            {
                EnglishUpper += EnglishLetter;
            }
            else
            {
                EnglishLower += EnglishLetter;
            }
            //              0     1                  23456789012345678901234567890123456789
            std::wcout << L"'" << EnglishLetter << L"'       " << std::dec << std::showbase << std::setw( 10 ) << ( ( int ) EnglishLetter ) << std::hex << std::showbase << std::setw( 10 ) << ( ( int ) EnglishLetter ) << std::oct << std::setw( 10 ) << ( ( int ) EnglishLetter ) << std::endl;
        }
    }
    const std::ctype < wchar_t >& facet = std::use_facet < std::ctype < wchar_t > >( std::locale( ) );
    std::wcout << L"Bulgarian    Decimal   Hex       Oct       " << std::endl;
    std::wstring BulgarianUpper;
    std::wstring BulgarianLower;
    //    for( unsigned int letterIndex = 0; letterIndex < 64; letterIndex++ )
    for( unsigned int letterIndex = 0; letterIndex < 32; letterIndex++ )
    {
        wchar_t BulgarianLetter = ( ( ( wchar_t ) L'\u0410' ) + letterIndex );
        BulgarianUpper += BulgarianLetter;
        BulgarianLower += facet.tolower( BulgarianLetter );
        std::wcout << L"'" << BulgarianLetter << L"'       " << std::dec << std::setw( 10 ) << ( ( int ) BulgarianLetter ) << std::hex << std::showbase << std::setw( 10 ) << ( ( int ) BulgarianLetter ) << std::oct << std::showbase << std::setw( 10 ) << ( ( int ) BulgarianLetter ) << std::endl;
//        std::wcout << L"'*'       " << std::dec << std::setw( 10 ) << ( (int) BulgarianLetter )  << std::hex << std::setw( 10 ) << ( (int) BulgarianLetter )  << std::oct << std::setw( 10 ) << ( (int) BulgarianLetter ) << std::endl;
    }
    for( unsigned int letterIndex = 0; letterIndex < 32; letterIndex++ )
   {
       wchar_t BulgarianLetter = ( ( ( wchar_t ) L'\u0410' ) + letterIndex );
       BulgarianLetter = facet.tolower( BulgarianLetter );
       std::wcout << L"'" << BulgarianLetter << L"'       " << std::dec << std::setw( 10 ) << ( ( int ) BulgarianLetter ) << std::hex << std::showbase << std::setw( 10 ) << ( ( int ) BulgarianLetter ) << std::oct << std::showbase << std::setw( 10 ) << ( ( int ) BulgarianLetter ) << std::endl;
//        std::wcout << L"'*'       " << std::dec << std::setw( 10 ) << ( (int) BulgarianLetter )  << std::hex << std::setw( 10 ) << ( (int) BulgarianLetter )  << std::oct << std::setw( 10 ) << ( (int) BulgarianLetter ) << std::endl;
   }
    std::wcout << "  English Upper: " << EnglishUpper << std::endl;
    std::wcout << "  English Lower: " << EnglishLower << std::endl;
    std::wcout << "Bulgarian Upper: " << BulgarianUpper << std::endl;
    std::wcout << "Bulgarian Lower: " << BulgarianLower << std::endl;

    return 0;
}

// locale::locale
//#include <iostream>       // std::cout
//#include <locale>         // std::locale
//#include <stdexcept>      // std::runtime_error
//#include <locale.h>
//

//#include <sstream>
//#include <iostream>
//#include <fstream>
//#include <codecvt>
//#include <locale>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//
//    std::wcin.imbue(std::locale(locale(""), new codecvt_utf8<wchar_t>));
//    std::wcerr.imbue(std::locale(locale(""), new codecvt_utf8<wchar_t>));
//
//    std::wstring userInput = L"ЖЖЖЖ";
////    getline(wcin, userInput);
//
//    std::wcerr << "Size of string is " << userInput.length() << std::endl;
//
//    for (int i = 0; i < userInput.length(); ++i)
//    {
//        std::wcerr << userInput.at(i) << std::endl;
//    }
//
//
////
////    setlocale( LC_ALL, "UTF-8");
////    setlocale( LC_COLLATE, "UTF-8");
////    setlocale( LC_CTYPE, "UTF-8");
////    setlocale( LC_MONETARY, "UTF-8");
////    setlocale( LC_NUMERIC, "UTF-8");
////    setlocale( LC_TIME, "UTF-8");
////
////
////    char dao [4] = "\u9053";
////
////    std::wcout << dao << std::endl;
////
////
////    std::wcout << L'Ж' << std::endl;
//
////    std::locale::global(std::locale("en_US.utf16LE"));
////    std::wcout.imbue(std::locale());
////    std::cout << "Max wchart_t = " << std::numeric_limits<unsigned short>::max() << std::endl;
////    std::wcout << L"English   Decimal   Hex       Oct       " << std::endl;
////    std::wcout << L"Decimal   Hex       Oct       " << std::endl;
////    for( wchar_t letter = 0; letter < 4000 ; letter++ )
////    {
////        //std::wcout << L"'" << letter << L"'       " << std::dec << std::setw( 10 ) << ( (int) letter )  << std::hex << std::setw( 10 ) << ( (int) letter )  << std::oct << std::setw( 10 ) << ( (int) letter ) << std::endl;
////        //std::wcout << std::dec << std::noshowbase << std::setw( 10 ) << ( (int) letter ) << std::setw( 10 ) << std::hex << std::showbase  << ( (int) letter ) << std::setw( 10 ) << std::oct << std::showbase << ( (int) letter ) << std::endl;
////    }
//
////    //              0123456789012345678901234567890123456789
////    std::wcout << L"English   Decimal   Hex       Oct       " << std::endl;
////    std::wstring EnglishAlphabet;
////    for( unsigned int letterIndex = 0; letterIndex < 52; letterIndex++ )
////    {
////        wchar_t EnglishLetter = ( ( ( wchar_t ) L'A' ) + letterIndex );
////        EnglishAlphabet += EnglishLetter;
////        //              0     1                  23456789012345678901234567890123456789
////        std::wcout << L"'" << EnglishLetter << L"'       " << std::dec << std::setw( 10 ) << ( (int) EnglishLetter )  << std::hex << std::setw( 10 ) << ( (int) EnglishLetter )  << std::oct << std::setw( 10 ) << ( (int) EnglishLetter ) << std::endl;
////    }
////    std::wcout << L"Bulgarian Decimal   Hex       Oct       " << std::endl;
////    std::wstring BulgarianAlphabet;
////    for( unsigned int letterIndex = 0; letterIndex < 64; letterIndex++ )
////    {
////        wchar_t BulgarianLetter = ( ( ( wchar_t ) L'\u1040' ) + letterIndex );
////        BulgarianAlphabet += BulgarianLetter;
//////        std::wcout << L"'" << BulgarianLetter << L"'       " << std::dec << std::setw( 10 ) << ( (int) BulgarianLetter )  << std::hex << std::setw( 10 ) << ( (int) BulgarianLetter )  << std::oct << std::setw( 10 ) << ( (int) BulgarianLetter ) << std::endl;
////        std::wcout << L"'*'       " << std::dec << std::setw( 10 ) << ( (int) BulgarianLetter )  << std::hex << std::setw( 10 ) << ( (int) BulgarianLetter )  << std::oct << std::setw( 10 ) << ( (int) BulgarianLetter ) << std::endl;
////     }
////    std::wcout << "  English Alphabet: " << EnglishAlphabet << std::endl;
////    std::wcout << "Bulgarian Alphabet: " << BulgarianAlphabet << std::endl;
//
//    return 0;
//}

// This started to work
//#include <codecvt>
//#include <iostream>
//
//int main()
//{
//
//    std::locale::global( std::locale( std::locale(""), new std::codecvt_utf8<wchar_t> ) );
//
//    std::wcin.imbue( std::locale() );
//    std::wcout.imbue( std::locale() );
//    std::wcerr.imbue( std::locale() );
//
//    std::wstring user_input = L"ЖЖЖЖ";
//
//    for( int i = 0; i < user_input.length(); ++i )
//    {
//        std::wcout << user_input[i] << std::endl;
//    }
//
//    // Converting characters to uppercase
//    const std::ctype < wchar_t > & f = std::use_facet < std::ctype < wchar_t > > ( std::locale() );
//
//    for( int i = 0; i < user_input.length(); ++i )
//    {
//        std::wcout << f.toupper(user_input[i]) << std::endl; // f.tolower() for lowercase
//    }
//
//    return 0;
//}

