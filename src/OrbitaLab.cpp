#include <Grapic.h>
using namespace grapic;

const int DIMW = 500;

struct Complex
{
    float x, y;
};

Complex make_complex(float x, float y)
{
    Complex c;
    c.x = x;
    c.y = y;
    return c;
};

float to_deg(float angle_rad)
{
    return (angle_rad*360)/(2*M_PI);
}

float to_rad(float angle_deg)
{
    return (angle_deg*2*M_PI)/360;
}

Complex make_complex_exp(float r, float theta_deg)
{
    Complex c;
    c.x = r*cos(to_rad(theta_deg));
    c.y = r*sin(to_rad(theta_deg));
    return c;
}

Complex operator+(Complex a, Complex b)
{
    Complex c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    return c;
}

Complex operator-(Complex a, Complex b)
{
    return make_complex(a.x-b.x, a.y-b.y);
}

Complex operator*(float lambda, Complex c)
{
    return make_complex(lambda*c.x, lambda*c.y);
}

Complex operator*(Complex c,float lambda)
{
    return make_complex(c.x*lambda, c.y*lambda);
}

Complex scale(Complex p, float cx, float cy, float lambda)
{
    Complex centre = make_complex(cx, cy);
    return(p-centre)*lambda+centre;
}

Complex operator*(Complex a, Complex b)
{
    return make_complex(a.x*b.x-a.y*b.y, a.x*b.y+a.y*b.x);
}

Complex rotate(Complex p, float cx, float cy, float theta_deg)
{
    Complex centre = make_complex(cx, cy);
    Complex rot = make_complex_exp(1, theta_deg);
    return (p-centre)*rot+centre;
}

struct SolarSystem
{
    Complex Sun, Earth, Moon, Mercury;
};

void Init(SolarSystem &S)
{
    S.Sun = make_complex(DIMW/2, DIMW/2);
    S.Mercury = S.Sun + make_complex(30, 0);
    S.Earth = S.Sun + make_complex(90, 0);
    S.Moon = S.Earth + make_complex(15, 0);
}

void draw(SolarSystem S)
{
    color(255,255,0); //jaune
    circleFill(S.Sun.x, S.Sun.y, 10);
    color(255,0,0); //rouge
    circleFill(S.Mercury.x, S.Mercury.y, 4);
    color(0,0,255); //blue
    circleFill(S.Earth.x, S.Earth.y, 5);
    color(255, 255, 255); //blanc
    circleFill(S.Moon.x, S.Moon.y, 2);
}

void update(SolarSystem &S)
{
    S.Mercury = rotate(S.Mercury, S.Sun.x, S.Sun.y, 0.001f);
    Complex Moonlocal = S.Moon - S.Earth;
    S.Earth = rotate(S.Earth,S.Sun.x, S.Sun.y, 0.0003f);
    S.Moon = Moonlocal + S.Earth;
    S.Moon = rotate (S.Moon, S.Earth.x, S.Earth.y, 0.0003f);
}


int main(int, char**)
{
    SolarSystem S;
    Init (S);
    winInit("SolarSystem", DIMW, DIMW);
    backgroundColor(0,0,0);
    bool stop = false;
    while( !stop)
    {
        winClear();
        draw (S);
        update(S);
        stop = false;

    }
    winQuit();
    return 0;

}