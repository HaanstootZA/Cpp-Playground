#ifndef ENUMS_H
#define ENUMS_H

struct Case{
    public:
        static const int FirstLetterInitial = 0;
        static const int ALLCAPS = 1;
        static const int nocaps = 2;
        static const int CamelCase = 3;
        static const int None = 4;
};

struct OrderBy{
    public:
        static const int Artist = 0;
        static const int Title = 1;
        static const int Album = 2;
        static const int Track = 3;
};

#endif // ENUMS_H
