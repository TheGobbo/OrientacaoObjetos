#if !defined(FORMA_HPP)
#define FORMA_HPP

class Forma {
   public:
    virtual ~Forma() = default;

    virtual double calculaArea() const = 0;
};

#endif  // FORMA_HPP
