#pragma once

class Prototype {
public:
    virtual ~Prototype() = default;

    // Retorna um ponteiro para permitir polimorfismo
    virtual Prototype* clone() const = 0; 
};
