#ifndef MOLAR_H
#define MOLAR_H

#include <QColor>
#include "teeth.h"

class Molar : public Teeth
{
public:
    Molar();

private:

    void paintGrid();
    void paintPart();
    void createPolygons();

};

#endif // MOLAR_H
