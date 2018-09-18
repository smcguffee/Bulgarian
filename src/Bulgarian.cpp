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
    for( unsigned int letterIndex = 0; letterIndex < 32; letterIndex++ )
    {
        if( letterIndex != 27 && letterIndex != 29 )
        {
            wchar_t BulgarianLetter = ( ( ( wchar_t ) L'\u0410' ) + letterIndex );
            BulgarianUpper += BulgarianLetter;
            BulgarianLower += facet.tolower( BulgarianLetter );
            std::wcout << L"'" << BulgarianLetter << L"'       " << std::dec << std::setw( 10 ) << ( ( int ) BulgarianLetter ) << std::hex << std::showbase << std::setw( 10 ) << ( ( int ) BulgarianLetter ) << std::oct << std::showbase << std::setw( 10 ) << ( ( int ) BulgarianLetter ) << std::endl;
        }
    }
    for( unsigned int letterIndex = 0; letterIndex < 32; letterIndex++ )
    {
        if( letterIndex != 27 && letterIndex != 29 )
        {
            wchar_t BulgarianLetter = ( ( ( wchar_t ) L'\u0410' ) + letterIndex );
            BulgarianLetter = facet.tolower( BulgarianLetter );
            std::wcout << L"'" << BulgarianLetter << L"'       " << std::dec << std::setw( 10 ) << ( ( int ) BulgarianLetter ) << std::hex << std::showbase << std::setw( 10 ) << ( ( int ) BulgarianLetter ) << std::oct << std::showbase << std::setw( 10 ) << ( ( int ) BulgarianLetter ) << std::endl;
        }
    }
    std::wcout << "  English Upper: " << EnglishUpper << std::endl;
    std::wcout << "  English Lower: " << EnglishLower << std::endl;
    std::wcout << "Bulgarian Upper: " << BulgarianUpper << std::endl;
    std::wcout << "Bulgarian Lower: " << BulgarianLower << std::endl;
    return 0;
}
