#include <decide/decide.hpp>

/*There exists at least one set of Q_PTS (consecutive data points) that lie in more than QUADS
(quadrants). Where there is ambiguity as to which quadrant contains a given point, priority
of decision will be by quadrant number, i.e., I, II, III, IV. For example, the data point (0,0)
is in quadrant I, the point (-l,0) is in quadrant II, the point (0,-l) is in quadrant III, the point
(0,1) is in quadrant I and the point (1,0) is in quadrant I.*/

int quad(Coordinate point){
    if (point.y>=0){
        if (point.x>=0){
            return 1;
        }
        else{
            return 2;
        }
    }
    else{
        if (point.x<=0){
            return 3;
        }
        else{
            return 4;
        }
    }
}

bool unique(int arr[], int goal, int size){
    int first=0;
    int second=0;
    int third=0;
    int forth=0;
    for (int i=0; i < size;i++){
        switch (arr[i])
        {
        case 1:
            if (first==0){
                 first++;
            }
            break;
        case 2:
            if (second==0){
                 second++;
            }
            break;
        case 3:
            if (third==0){
                 third++;
            }
            break;
        case 4:
            if (forth==0){
                 forth++;
            }
            break;
        }
    }
    if ((first+second+third+forth)>goal){
        return true;
    }
    return false;
}

bool lic4(Points points, Parameters param){ 
    int qpts=param.QPTS;
    int npts=points.size();
    if (qpts<2 || qpts>npts){
        return false;
    }
    if (1<=param.QUADS<=3){
        for (int i=0; i<npts;i++){
            int position[qpts];
            if ((i+qpts-1)<npts){
                for (int a=0; a<qpts; a++){
                    position[a]=quad(points[i+a]);
                }
            }
            if (unique(position, param.QUADS, qpts)){
                return true;
            }
        }
        return false;
    }
    else{
        return false;
    }

}