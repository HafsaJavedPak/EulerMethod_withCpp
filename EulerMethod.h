struct points {
    double P[2];
};

class EulerMethod {
public:
    double length;
    points *Eulerpoints;
    
    EulerMethod(int range, double x0, double y0, double delta = 0.001) {
        h = delta;
        length = range / h;
        Eulerpoints = new points[(int)length];
        Eulerpoints[0] = {x0, y0};
        applyEuler(Eulerpoints, x0, y0);
    }
    
protected:
    double h;

private:
    void applyEuler(points *pointer, double x0, double y0) {
        double x, y, m;
        
        for (int i = 1; i < length; i++) {
            x = pointer[i - 1].P[0];
            y = pointer[i - 1].P[1];
            m = slope(x, y);
            pointer[i] = {x + h, y + m * h};
        }
    }

    double slope(double x, double y) {
        double res =  -x/y;
        return res;
    }

};
   