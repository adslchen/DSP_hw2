#include<iostream>
#include<fstream>
using namespace std;


int 
main(int argc, char** argv)
{
   int gaussian = atoi(argv[1]);
   int sil = atoi(argv[2]);
   int proto_state = atoi(argv[3]);
   int fuck = atoi(argv[4]);
//   string ss = string(argv[2]);


   ofstream fout("mix2_10.hed");
   fout << "MU " << gaussian << " {liN.state[" << 2 << "-" << fuck<< "].mix}" <<endl;
   fout << "MU " << gaussian << " {#i.state[" << 2 << "-" << fuck << "].mix}" <<endl;
   fout << "MU " << gaussian << " {#er.state[" << 2 << "-"<< fuck << "].mix}" <<endl;
   fout << "MU " << gaussian << " {san.state[" << 2 << "-"<< fuck << "].mix}" <<endl;
   fout << "MU " << gaussian << " {sy.state[" << 2 << "-"<< fuck << "].mix}" <<endl;
   fout << "MU " << gaussian << " {#u.state[" << 2 << "-" << fuck << "].mix}" <<endl;
   fout << "MU " << gaussian << " {liou.state[" <<  2 << "-" << fuck << "].mix}" <<endl;
  
   fout << "MU " << gaussian << " {qi.state[" <<  2 << "-" << fuck << "].mix}" <<endl;

   fout << "MU " << gaussian << " {ba.state[" <<  2 << "-" << fuck << "].mix}" <<endl;
   fout << "MU " << gaussian << " {jiou.state[" <<  2 << "-" << fuck << "].mix}" <<endl;
   fout << "MU " << sil << " {sil.state[" << 2 << "-" << 1+sil << "].mix}" <<endl;
   fout.close();
   ofstream fout1("proto");

   fout1 << "~o <VECSIZE> 39 <MFCC_Z_E_D_A>" << endl
     << "~h \"proto\"" << endl
     << "<BeginHMM>" << endl 
     << "<NumStates> " << 2+ proto_state  << endl;
   for(int i = 0 ;i < proto_state; i++){
     fout1 << "<State> " << i+2 << endl
     <<  "<Mean> 39" << endl
       << "0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0" << endl
     <<  "<Variance> 39" << endl
       << "1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0 1.0" << endl;
   }
   fout1 << "<TransP> " << proto_state+2 << endl;
  //   << "0.0 1.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0" <<endl;
   for(int i = 0; i < proto_state+2; i++){
     for(int j = 0 ; j < proto_state+2; j++){
       if(i==0){
         if(j == 1) fout1 << "1.0 ";
         else fout1 << "0.0 ";
       }
       else if( i != proto_state+1 && (j == i || j == i+1)) fout1 << 0.5 << " ";
       else if(i == proto_state +1 ) fout1 << "0.0 ";
       else fout1 << "0.0 ";
     }
     fout1 << endl;
   }
  fout1 << "<EndHMM>" << endl;
  fout1.close();
}
