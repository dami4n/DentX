#ifndef INCISOR_H
#define INCISOR_H

#include "teeth.h"

class Incisor : public Teeth
{
public:
    Incisor();

private:
    void paintGrid();
    void paintPart();
    void createPolygons();

};

#endif // INCISOR_H
