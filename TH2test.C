void TH2test()
{
  TH2Poly *poly = new TH2Poly();
  int MAXVERTICES = 6;
  double HexX[MAXVERTICES];
  double HexY[MAXVERTICES];
  double positionX, positionY, centerX, centerY;
  int iu,iv,CellXYsize,Daisy_N;
  ifstream file("poly_frame.txt");
  string line;
  ifstream daisyfile("daisy_frame_center_position.txt");
  TCanvas* c1 = new TCanvas();
  

  for(int header = 0; header < 4; ++header )     getline(file,line);
  daisyfile >> Daisy_N;
  
  for(int j = 0; j < Daisy_N ; j++){
    daisyfile >> centerX >> centerY;
    if( file.eof() ) {
      file.clear();
      file.seekg(0, ios::beg);
      for(int header = 0; header < 4; ++header )     getline(file,line);
    } 
    while(!file.eof()){
      file >> iu >> iv >> CellXYsize;
      for(int i = 0; i < CellXYsize ; ++i){
	file >> positionX >> positionY;
	HexX[i] = centerX + positionX;
	HexY[i] = centerY + positionY;
      }
      poly->AddBin(CellXYsize, HexX, HexY);
    }
  }
  file.close();
  daisyfile.close();

  poly->Fill(1.0,1.0,10);

  poly->Draw("colz");
  c1->Update();
  
}


