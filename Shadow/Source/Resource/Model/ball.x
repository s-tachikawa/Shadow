xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 130;
 0.00000;1.00000;0.00000;,
 0.18164;0.95106;-0.25000;,
 0.00000;0.95106;-0.30902;,
 0.00000;1.00000;0.00000;,
 0.29389;0.95106;-0.09549;,
 0.00000;1.00000;0.00000;,
 0.29389;0.95106;0.09549;,
 0.00000;1.00000;0.00000;,
 0.18164;0.95106;0.25000;,
 0.00000;1.00000;0.00000;,
 -0.00000;0.95106;0.30902;,
 0.00000;1.00000;0.00000;,
 -0.18164;0.95106;0.25000;,
 0.00000;1.00000;0.00000;,
 -0.29389;0.95106;0.09549;,
 0.00000;1.00000;0.00000;,
 -0.29389;0.95106;-0.09549;,
 0.00000;1.00000;0.00000;,
 -0.18164;0.95106;-0.25000;,
 0.00000;1.00000;0.00000;,
 0.00000;0.95106;-0.30902;,
 0.00000;-0.95106;-0.30902;,
 0.18164;-0.95106;-0.25000;,
 0.00000;-1.00000;-0.00000;,
 0.29389;-0.95106;-0.09549;,
 0.00000;-1.00000;-0.00000;,
 0.29389;-0.95106;0.09549;,
 0.00000;-1.00000;-0.00000;,
 0.18164;-0.95106;0.25000;,
 0.00000;-1.00000;-0.00000;,
 -0.00000;-0.95106;0.30902;,
 0.00000;-1.00000;-0.00000;,
 -0.18164;-0.95106;0.25000;,
 0.00000;-1.00000;-0.00000;,
 -0.29389;-0.95106;0.09549;,
 0.00000;-1.00000;-0.00000;,
 -0.29389;-0.95106;-0.09549;,
 0.00000;-1.00000;-0.00000;,
 -0.18164;-0.95106;-0.25000;,
 0.00000;-1.00000;-0.00000;,
 0.00000;-0.95106;-0.30902;,
 0.00000;-1.00000;-0.00000;,
 0.00000;0.80902;-0.58779;,
 0.34549;0.80902;-0.47553;,
 0.00000;0.58779;-0.80902;,
 0.47553;0.58779;-0.65451;,
 0.00000;0.30902;-0.95106;,
 0.55902;0.30902;-0.76942;,
 0.00000;-0.00000;-1.00000;,
 0.58779;-0.00000;-0.80902;,
 0.00000;-0.30902;-0.95106;,
 0.55902;-0.30902;-0.76942;,
 0.00000;-0.58779;-0.80902;,
 0.47553;-0.58779;-0.65451;,
 0.00000;-0.80902;-0.58779;,
 0.34549;-0.80902;-0.47553;,
 0.00000;-0.95106;-0.30902;,
 0.18164;-0.95106;-0.25000;,
 -0.18164;-0.95106;-0.25000;,
 -0.34549;-0.80902;-0.47553;,
 0.00000;-0.80902;-0.58779;,
 0.00000;-0.95106;-0.30902;,
 -0.47553;-0.58779;-0.65451;,
 0.00000;-0.58779;-0.80902;,
 -0.55902;-0.30902;-0.76942;,
 0.00000;-0.30902;-0.95106;,
 -0.58778;-0.00000;-0.80902;,
 0.00000;-0.00000;-1.00000;,
 -0.55902;0.30902;-0.76942;,
 0.00000;0.30902;-0.95106;,
 -0.47553;0.58779;-0.65451;,
 0.00000;0.58779;-0.80902;,
 -0.34549;0.80902;-0.47553;,
 0.00000;0.80902;-0.58779;,
 -0.55902;0.80902;-0.18164;,
 -0.76942;0.58779;-0.25000;,
 -0.90451;0.30902;-0.29389;,
 -0.95106;-0.00000;-0.30902;,
 -0.90451;-0.30902;-0.29389;,
 -0.76942;-0.58779;-0.25000;,
 -0.55902;-0.80902;-0.18164;,
 -0.29389;-0.95106;-0.09549;,
 -0.55902;0.80902;0.18164;,
 -0.76942;0.58779;0.25000;,
 -0.90451;0.30902;0.29389;,
 -0.95106;-0.00000;0.30902;,
 -0.90451;-0.30902;0.29389;,
 -0.76942;-0.58779;0.25000;,
 -0.55902;-0.80902;0.18164;,
 -0.29389;-0.95106;0.09549;,
 -0.34549;0.80902;0.47553;,
 -0.47553;0.58779;0.65451;,
 -0.55902;0.30902;0.76942;,
 -0.58779;-0.00000;0.80902;,
 -0.55902;-0.30902;0.76942;,
 -0.47553;-0.58779;0.65451;,
 -0.34549;-0.80902;0.47553;,
 -0.18164;-0.95106;0.25000;,
 -0.00000;-0.95106;0.30902;,
 -0.00000;-0.80902;0.58779;,
 -0.00000;-0.58779;0.80902;,
 -0.00000;-0.30902;0.95106;,
 -0.00000;-0.00000;1.00000;,
 -0.00000;0.30902;0.95106;,
 -0.00000;0.58779;0.80902;,
 -0.00000;0.80902;0.58779;,
 0.34549;0.80902;0.47553;,
 0.47553;0.58779;0.65451;,
 0.55902;0.30902;0.76942;,
 0.58779;-0.00000;0.80902;,
 0.55902;-0.30902;0.76942;,
 0.47553;-0.58779;0.65451;,
 0.34549;-0.80902;0.47553;,
 0.18164;-0.95106;0.25000;,
 0.29389;-0.95106;0.09549;,
 0.55902;-0.80902;0.18164;,
 0.76942;-0.58779;0.25000;,
 0.90451;-0.30902;0.29389;,
 0.95106;-0.00000;0.30902;,
 0.90451;0.30902;0.29389;,
 0.76942;0.58779;0.25000;,
 0.55902;0.80902;0.18164;,
 0.55902;0.80902;-0.18164;,
 0.76942;0.58779;-0.25000;,
 0.90451;0.30902;-0.29389;,
 0.95106;-0.00000;-0.30902;,
 0.90451;-0.30902;-0.29389;,
 0.76942;-0.58779;-0.25000;,
 0.55902;-0.80902;-0.18164;,
 0.29389;-0.95106;-0.09549;;
 
 180;
 3;0,1,2;,
 3;3,4,1;,
 3;5,6,4;,
 3;7,8,6;,
 3;9,10,8;,
 3;11,12,10;,
 3;13,14,12;,
 3;15,16,14;,
 3;17,18,16;,
 3;19,20,18;,
 3;21,22,23;,
 3;22,24,25;,
 3;24,26,27;,
 3;26,28,29;,
 3;28,30,31;,
 3;30,32,33;,
 3;32,34,35;,
 3;34,36,37;,
 3;36,38,39;,
 3;38,40,41;,
 3;42,2,1;,
 3;42,1,43;,
 3;44,42,43;,
 3;44,43,45;,
 3;46,44,45;,
 3;46,45,47;,
 3;48,46,47;,
 3;48,47,49;,
 3;50,48,49;,
 3;50,49,51;,
 3;52,50,51;,
 3;52,51,53;,
 3;54,52,53;,
 3;54,53,55;,
 3;56,54,55;,
 3;56,55,57;,
 3;58,59,60;,
 3;58,60,61;,
 3;59,62,63;,
 3;59,63,60;,
 3;62,64,65;,
 3;62,65,63;,
 3;64,66,67;,
 3;64,67,65;,
 3;66,68,69;,
 3;66,69,67;,
 3;68,70,71;,
 3;68,71,69;,
 3;70,72,73;,
 3;70,73,71;,
 3;72,18,20;,
 3;72,20,73;,
 3;74,16,18;,
 3;74,18,72;,
 3;75,74,72;,
 3;75,72,70;,
 3;76,75,70;,
 3;76,70,68;,
 3;77,76,68;,
 3;77,68,66;,
 3;78,77,66;,
 3;78,66,64;,
 3;79,78,64;,
 3;79,64,62;,
 3;80,79,62;,
 3;80,62,59;,
 3;81,80,59;,
 3;81,59,58;,
 3;82,14,16;,
 3;82,16,74;,
 3;83,82,74;,
 3;83,74,75;,
 3;84,83,75;,
 3;84,75,76;,
 3;85,84,76;,
 3;85,76,77;,
 3;86,85,77;,
 3;86,77,78;,
 3;87,86,78;,
 3;87,78,79;,
 3;88,87,79;,
 3;88,79,80;,
 3;89,88,80;,
 3;89,80,81;,
 3;90,12,14;,
 3;90,14,82;,
 3;91,90,82;,
 3;91,82,83;,
 3;92,91,83;,
 3;92,83,84;,
 3;93,92,84;,
 3;93,84,85;,
 3;94,93,85;,
 3;94,85,86;,
 3;95,94,86;,
 3;95,86,87;,
 3;96,95,87;,
 3;96,87,88;,
 3;97,96,88;,
 3;97,88,89;,
 3;98,99,96;,
 3;98,96,97;,
 3;99,100,95;,
 3;99,95,96;,
 3;100,101,94;,
 3;100,94,95;,
 3;101,102,93;,
 3;101,93,94;,
 3;102,103,92;,
 3;102,92,93;,
 3;103,104,91;,
 3;103,91,92;,
 3;104,105,90;,
 3;104,90,91;,
 3;105,10,12;,
 3;105,12,90;,
 3;106,8,10;,
 3;106,10,105;,
 3;107,106,105;,
 3;107,105,104;,
 3;108,107,104;,
 3;108,104,103;,
 3;109,108,103;,
 3;109,103,102;,
 3;110,109,102;,
 3;110,102,101;,
 3;111,110,101;,
 3;111,101,100;,
 3;112,111,100;,
 3;112,100,99;,
 3;113,112,99;,
 3;113,99,98;,
 3;114,115,112;,
 3;114,112,113;,
 3;115,116,111;,
 3;115,111,112;,
 3;116,117,110;,
 3;116,110,111;,
 3;117,118,109;,
 3;117,109,110;,
 3;118,119,108;,
 3;118,108,109;,
 3;119,120,107;,
 3;119,107,108;,
 3;120,121,106;,
 3;120,106,107;,
 3;121,6,8;,
 3;121,8,106;,
 3;122,4,6;,
 3;122,6,121;,
 3;43,1,4;,
 3;43,4,122;,
 3;45,43,122;,
 3;45,122,123;,
 3;123,122,121;,
 3;123,121,120;,
 3;124,123,120;,
 3;124,120,119;,
 3;47,45,123;,
 3;47,123,124;,
 3;125,124,119;,
 3;125,119,118;,
 3;49,47,124;,
 3;49,124,125;,
 3;126,125,118;,
 3;126,118,117;,
 3;51,49,125;,
 3;51,125,126;,
 3;127,126,117;,
 3;127,117,116;,
 3;53,51,126;,
 3;53,126,127;,
 3;128,127,116;,
 3;128,116,115;,
 3;55,53,127;,
 3;55,127,128;,
 3;129,128,115;,
 3;129,115,114;,
 3;57,55,128;,
 3;57,128,129;;
 
 MeshMaterialList {
  1;
  180;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  92;
  0.000000;1.000000;0.000000;,
  -0.029729;0.940624;-0.338146;,
  0.174706;0.940624;-0.291040;,
  0.312409;0.940624;-0.132767;,
  0.330783;0.940624;0.076219;,
  0.222809;0.940624;0.256092;,
  0.029729;0.940624;0.338146;,
  -0.174706;0.940624;0.291040;,
  -0.312409;0.940624;0.132767;,
  -0.330783;0.940624;-0.076219;,
  -0.222809;0.940624;-0.256092;,
  -0.013401;0.809640;-0.586774;,
  0.334056;0.809640;-0.482587;,
  0.553914;0.809640;-0.194068;,
  0.562196;0.809640;0.168578;,
  0.355738;0.809640;0.466833;,
  0.013401;0.809640;0.586774;,
  -0.334056;0.809640;0.482587;,
  -0.553914;0.809640;0.194068;,
  -0.562196;0.809640;-0.168578;,
  -0.355738;0.809640;-0.466833;,
  -0.009446;0.588689;-0.808304;,
  0.467467;0.588689;-0.659484;,
  0.765824;0.588689;-0.258764;,
  0.771662;0.588689;0.240796;,
  0.482752;0.588689;0.648380;,
  0.009446;0.588689;0.808304;,
  -0.467467;0.588689;0.659484;,
  -0.765824;0.588689;0.258764;,
  -0.771662;0.588689;-0.240796;,
  -0.482751;0.588689;-0.648380;,
  -0.004849;0.309674;-0.950831;,
  0.554961;0.309674;-0.772088;,
  0.902795;0.309674;-0.298435;,
  0.905792;0.309674;0.289211;,
  0.562807;0.309674;0.766388;,
  0.004849;0.309674;0.950831;,
  -0.554961;0.309674;0.772088;,
  -0.902795;0.309674;0.298435;,
  -0.905792;0.309674;-0.289211;,
  -0.562807;0.309674;-0.766388;,
  0.000000;-0.000000;-1.000000;,
  0.587785;-0.000000;-0.809017;,
  0.951056;-0.000000;-0.309017;,
  0.951056;-0.000000;0.309017;,
  0.587785;-0.000000;0.809017;,
  -0.000000;0.000000;1.000000;,
  -0.587785;-0.000000;0.809017;,
  -0.951056;-0.000000;0.309017;,
  -0.951056;-0.000000;-0.309017;,
  -0.587785;-0.000000;-0.809017;,
  0.004849;-0.309674;-0.950831;,
  0.562807;-0.309674;-0.766388;,
  0.905792;-0.309674;-0.289211;,
  0.902795;-0.309674;0.298435;,
  0.554961;-0.309674;0.772088;,
  -0.004849;-0.309674;0.950830;,
  -0.562807;-0.309674;0.766388;,
  -0.905792;-0.309674;0.289211;,
  -0.902795;-0.309674;-0.298435;,
  -0.554961;-0.309674;-0.772088;,
  0.009446;-0.588689;-0.808304;,
  0.482752;-0.588689;-0.648380;,
  0.771662;-0.588689;-0.240796;,
  0.765824;-0.588689;0.258764;,
  0.467467;-0.588689;0.659484;,
  -0.009446;-0.588689;0.808304;,
  -0.482752;-0.588689;0.648380;,
  -0.771662;-0.588689;0.240796;,
  -0.765824;-0.588689;-0.258764;,
  -0.467467;-0.588689;-0.659485;,
  0.013401;-0.809640;-0.586774;,
  0.355738;-0.809640;-0.466833;,
  0.562196;-0.809640;-0.168578;,
  0.553914;-0.809640;0.194068;,
  0.334056;-0.809640;0.482587;,
  -0.013401;-0.809640;0.586774;,
  -0.355738;-0.809640;0.466833;,
  -0.562196;-0.809640;0.168578;,
  -0.553914;-0.809640;-0.194068;,
  -0.334056;-0.809640;-0.482587;,
  0.029729;-0.940624;-0.338146;,
  0.222809;-0.940624;-0.256092;,
  0.330783;-0.940624;-0.076219;,
  0.312409;-0.940624;0.132767;,
  0.174706;-0.940624;0.291040;,
  -0.029729;-0.940624;0.338146;,
  -0.222809;-0.940624;0.256092;,
  -0.330783;-0.940624;0.076219;,
  -0.312409;-0.940624;-0.132767;,
  -0.174706;-0.940624;-0.291040;,
  0.000000;-1.000000;-0.000000;;
  180;
  3;0,2,1;,
  3;0,3,2;,
  3;0,4,3;,
  3;0,5,4;,
  3;0,6,5;,
  3;0,7,6;,
  3;0,8,7;,
  3;0,9,8;,
  3;0,10,9;,
  3;0,1,10;,
  3;81,82,91;,
  3;82,83,91;,
  3;83,84,91;,
  3;84,85,91;,
  3;85,86,91;,
  3;86,87,91;,
  3;87,88,91;,
  3;88,89,91;,
  3;89,90,91;,
  3;90,81,91;,
  3;11,1,2;,
  3;11,2,12;,
  3;21,11,12;,
  3;21,12,22;,
  3;31,21,22;,
  3;31,22,32;,
  3;41,31,32;,
  3;41,32,42;,
  3;51,41,42;,
  3;51,42,52;,
  3;61,51,52;,
  3;61,52,62;,
  3;71,61,62;,
  3;71,62,72;,
  3;81,71,72;,
  3;81,72,82;,
  3;90,80,71;,
  3;90,71,81;,
  3;80,70,61;,
  3;80,61,71;,
  3;70,60,51;,
  3;70,51,61;,
  3;60,50,41;,
  3;60,41,51;,
  3;50,40,31;,
  3;50,31,41;,
  3;40,30,21;,
  3;40,21,31;,
  3;30,20,11;,
  3;30,11,21;,
  3;20,10,1;,
  3;20,1,11;,
  3;19,9,10;,
  3;19,10,20;,
  3;29,19,20;,
  3;29,20,30;,
  3;39,29,30;,
  3;39,30,40;,
  3;49,39,40;,
  3;49,40,50;,
  3;59,49,50;,
  3;59,50,60;,
  3;69,59,60;,
  3;69,60,70;,
  3;79,69,70;,
  3;79,70,80;,
  3;89,79,80;,
  3;89,80,90;,
  3;18,8,9;,
  3;18,9,19;,
  3;28,18,19;,
  3;28,19,29;,
  3;38,28,29;,
  3;38,29,39;,
  3;48,38,39;,
  3;48,39,49;,
  3;58,48,49;,
  3;58,49,59;,
  3;68,58,59;,
  3;68,59,69;,
  3;78,68,69;,
  3;78,69,79;,
  3;88,78,79;,
  3;88,79,89;,
  3;17,7,8;,
  3;17,8,18;,
  3;27,17,18;,
  3;27,18,28;,
  3;37,27,28;,
  3;37,28,38;,
  3;47,37,38;,
  3;47,38,48;,
  3;57,47,48;,
  3;57,48,58;,
  3;67,57,58;,
  3;67,58,68;,
  3;77,67,68;,
  3;77,68,78;,
  3;87,77,78;,
  3;87,78,88;,
  3;86,76,77;,
  3;86,77,87;,
  3;76,66,67;,
  3;76,67,77;,
  3;66,56,57;,
  3;66,57,67;,
  3;56,46,47;,
  3;56,47,57;,
  3;46,36,37;,
  3;46,37,47;,
  3;36,26,27;,
  3;36,27,37;,
  3;26,16,17;,
  3;26,17,27;,
  3;16,6,7;,
  3;16,7,17;,
  3;15,5,6;,
  3;15,6,16;,
  3;25,15,16;,
  3;25,16,26;,
  3;35,25,26;,
  3;35,26,36;,
  3;45,35,36;,
  3;45,36,46;,
  3;55,45,46;,
  3;55,46,56;,
  3;65,55,56;,
  3;65,56,66;,
  3;75,65,66;,
  3;75,66,76;,
  3;85,75,76;,
  3;85,76,86;,
  3;84,74,75;,
  3;84,75,85;,
  3;74,64,65;,
  3;74,65,75;,
  3;64,54,55;,
  3;64,55,65;,
  3;54,44,45;,
  3;54,45,55;,
  3;44,34,35;,
  3;44,35,45;,
  3;34,24,25;,
  3;34,25,35;,
  3;24,14,15;,
  3;24,15,25;,
  3;14,4,5;,
  3;14,5,15;,
  3;13,3,4;,
  3;13,4,14;,
  3;12,2,3;,
  3;12,3,13;,
  3;22,12,13;,
  3;22,13,23;,
  3;23,13,14;,
  3;23,14,24;,
  3;33,23,24;,
  3;33,24,34;,
  3;32,22,23;,
  3;32,23,33;,
  3;43,33,34;,
  3;43,34,44;,
  3;42,32,33;,
  3;42,33,43;,
  3;53,43,44;,
  3;53,44,54;,
  3;52,42,43;,
  3;52,43,53;,
  3;63,53,54;,
  3;63,54,64;,
  3;62,52,53;,
  3;62,53,63;,
  3;73,63,64;,
  3;73,64,74;,
  3;72,62,63;,
  3;72,63,73;,
  3;83,73,74;,
  3;83,74,84;,
  3;82,72,73;,
  3;82,73,83;;
 }
 MeshTextureCoords {
  130;
  0.050000;0.000000;,
  0.100000;0.100000;,
  0.000000;0.100000;,
  0.150000;0.000000;,
  0.200000;0.100000;,
  0.250000;0.000000;,
  0.300000;0.100000;,
  0.350000;0.000000;,
  0.400000;0.100000;,
  0.450000;0.000000;,
  0.500000;0.100000;,
  0.550000;0.000000;,
  0.600000;0.100000;,
  0.650000;0.000000;,
  0.700000;0.100000;,
  0.750000;0.000000;,
  0.800000;0.100000;,
  0.850000;0.000000;,
  0.900000;0.100000;,
  0.950000;0.000000;,
  1.000000;0.100000;,
  0.000000;0.900000;,
  0.100000;0.900000;,
  0.050000;1.000000;,
  0.200000;0.900000;,
  0.150000;1.000000;,
  0.300000;0.900000;,
  0.250000;1.000000;,
  0.400000;0.900000;,
  0.350000;1.000000;,
  0.500000;0.900000;,
  0.450000;1.000000;,
  0.600000;0.900000;,
  0.550000;1.000000;,
  0.700000;0.900000;,
  0.650000;1.000000;,
  0.800000;0.900000;,
  0.750000;1.000000;,
  0.900000;0.900000;,
  0.850000;1.000000;,
  1.000000;0.900000;,
  0.950000;1.000000;,
  0.000000;0.200000;,
  0.100000;0.200000;,
  0.000000;0.300000;,
  0.100000;0.300000;,
  0.000000;0.400000;,
  0.100000;0.400000;,
  0.000000;0.500000;,
  0.100000;0.500000;,
  0.000000;0.600000;,
  0.100000;0.600000;,
  0.000000;0.700000;,
  0.100000;0.700000;,
  0.000000;0.800000;,
  0.100000;0.800000;,
  0.000000;0.900000;,
  0.100000;0.900000;,
  0.900000;0.900000;,
  0.900000;0.800000;,
  1.000000;0.800000;,
  1.000000;0.900000;,
  0.900000;0.700000;,
  1.000000;0.700000;,
  0.900000;0.600000;,
  1.000000;0.600000;,
  0.900000;0.500000;,
  1.000000;0.500000;,
  0.900000;0.400000;,
  1.000000;0.400000;,
  0.900000;0.300000;,
  1.000000;0.300000;,
  0.900000;0.200000;,
  1.000000;0.200000;,
  0.800000;0.200000;,
  0.800000;0.300000;,
  0.800000;0.400000;,
  0.800000;0.500000;,
  0.800000;0.600000;,
  0.800000;0.700000;,
  0.800000;0.800000;,
  0.800000;0.900000;,
  0.700000;0.200000;,
  0.700000;0.300000;,
  0.700000;0.400000;,
  0.700000;0.500000;,
  0.700000;0.600000;,
  0.700000;0.700000;,
  0.700000;0.800000;,
  0.700000;0.900000;,
  0.600000;0.200000;,
  0.600000;0.300000;,
  0.600000;0.400000;,
  0.600000;0.500000;,
  0.600000;0.600000;,
  0.600000;0.700000;,
  0.600000;0.800000;,
  0.600000;0.900000;,
  0.500000;0.900000;,
  0.500000;0.800000;,
  0.500000;0.700000;,
  0.500000;0.600000;,
  0.500000;0.500000;,
  0.500000;0.400000;,
  0.500000;0.300000;,
  0.500000;0.200000;,
  0.400000;0.200000;,
  0.400000;0.300000;,
  0.400000;0.400000;,
  0.400000;0.500000;,
  0.400000;0.600000;,
  0.400000;0.700000;,
  0.400000;0.800000;,
  0.400000;0.900000;,
  0.300000;0.900000;,
  0.300000;0.800000;,
  0.300000;0.700000;,
  0.300000;0.600000;,
  0.300000;0.500000;,
  0.300000;0.400000;,
  0.300000;0.300000;,
  0.300000;0.200000;,
  0.200000;0.200000;,
  0.200000;0.300000;,
  0.200000;0.400000;,
  0.200000;0.500000;,
  0.200000;0.600000;,
  0.200000;0.700000;,
  0.200000;0.800000;,
  0.200000;0.900000;;
 }
 MeshVertexColors {
  130;
  0;1.000000;1.000000;1.000000;1.000000;,
  1;1.000000;1.000000;1.000000;1.000000;,
  2;1.000000;1.000000;1.000000;1.000000;,
  3;1.000000;1.000000;1.000000;1.000000;,
  4;1.000000;1.000000;1.000000;1.000000;,
  5;1.000000;1.000000;1.000000;1.000000;,
  6;1.000000;1.000000;1.000000;1.000000;,
  7;1.000000;1.000000;1.000000;1.000000;,
  8;1.000000;1.000000;1.000000;1.000000;,
  9;1.000000;1.000000;1.000000;1.000000;,
  10;1.000000;1.000000;1.000000;1.000000;,
  11;1.000000;1.000000;1.000000;1.000000;,
  12;1.000000;1.000000;1.000000;1.000000;,
  13;1.000000;1.000000;1.000000;1.000000;,
  14;1.000000;1.000000;1.000000;1.000000;,
  15;1.000000;1.000000;1.000000;1.000000;,
  16;1.000000;1.000000;1.000000;1.000000;,
  17;1.000000;1.000000;1.000000;1.000000;,
  18;1.000000;1.000000;1.000000;1.000000;,
  19;1.000000;1.000000;1.000000;1.000000;,
  20;1.000000;1.000000;1.000000;1.000000;,
  21;1.000000;1.000000;1.000000;1.000000;,
  22;1.000000;1.000000;1.000000;1.000000;,
  23;1.000000;1.000000;1.000000;1.000000;,
  24;1.000000;1.000000;1.000000;1.000000;,
  25;1.000000;1.000000;1.000000;1.000000;,
  26;1.000000;1.000000;1.000000;1.000000;,
  27;1.000000;1.000000;1.000000;1.000000;,
  28;1.000000;1.000000;1.000000;1.000000;,
  29;1.000000;1.000000;1.000000;1.000000;,
  30;1.000000;1.000000;1.000000;1.000000;,
  31;1.000000;1.000000;1.000000;1.000000;,
  32;1.000000;1.000000;1.000000;1.000000;,
  33;1.000000;1.000000;1.000000;1.000000;,
  34;1.000000;1.000000;1.000000;1.000000;,
  35;1.000000;1.000000;1.000000;1.000000;,
  36;1.000000;1.000000;1.000000;1.000000;,
  37;1.000000;1.000000;1.000000;1.000000;,
  38;1.000000;1.000000;1.000000;1.000000;,
  39;1.000000;1.000000;1.000000;1.000000;,
  40;1.000000;1.000000;1.000000;1.000000;,
  41;1.000000;1.000000;1.000000;1.000000;,
  42;1.000000;1.000000;1.000000;1.000000;,
  43;1.000000;1.000000;1.000000;1.000000;,
  44;1.000000;1.000000;1.000000;1.000000;,
  45;1.000000;1.000000;1.000000;1.000000;,
  46;1.000000;1.000000;1.000000;1.000000;,
  47;1.000000;1.000000;1.000000;1.000000;,
  48;1.000000;1.000000;1.000000;1.000000;,
  49;1.000000;1.000000;1.000000;1.000000;,
  50;1.000000;1.000000;1.000000;1.000000;,
  51;1.000000;1.000000;1.000000;1.000000;,
  52;1.000000;1.000000;1.000000;1.000000;,
  53;1.000000;1.000000;1.000000;1.000000;,
  54;1.000000;1.000000;1.000000;1.000000;,
  55;1.000000;1.000000;1.000000;1.000000;,
  56;1.000000;1.000000;1.000000;1.000000;,
  57;1.000000;1.000000;1.000000;1.000000;,
  58;1.000000;1.000000;1.000000;1.000000;,
  59;1.000000;1.000000;1.000000;1.000000;,
  60;1.000000;1.000000;1.000000;1.000000;,
  61;1.000000;1.000000;1.000000;1.000000;,
  62;1.000000;1.000000;1.000000;1.000000;,
  63;1.000000;1.000000;1.000000;1.000000;,
  64;1.000000;1.000000;1.000000;1.000000;,
  65;1.000000;1.000000;1.000000;1.000000;,
  66;1.000000;1.000000;1.000000;1.000000;,
  67;1.000000;1.000000;1.000000;1.000000;,
  68;1.000000;1.000000;1.000000;1.000000;,
  69;1.000000;1.000000;1.000000;1.000000;,
  70;1.000000;1.000000;1.000000;1.000000;,
  71;1.000000;1.000000;1.000000;1.000000;,
  72;1.000000;1.000000;1.000000;1.000000;,
  73;1.000000;1.000000;1.000000;1.000000;,
  74;1.000000;1.000000;1.000000;1.000000;,
  75;1.000000;1.000000;1.000000;1.000000;,
  76;1.000000;1.000000;1.000000;1.000000;,
  77;1.000000;1.000000;1.000000;1.000000;,
  78;1.000000;1.000000;1.000000;1.000000;,
  79;1.000000;1.000000;1.000000;1.000000;,
  80;1.000000;1.000000;1.000000;1.000000;,
  81;1.000000;1.000000;1.000000;1.000000;,
  82;1.000000;1.000000;1.000000;1.000000;,
  83;1.000000;1.000000;1.000000;1.000000;,
  84;1.000000;1.000000;1.000000;1.000000;,
  85;1.000000;1.000000;1.000000;1.000000;,
  86;1.000000;1.000000;1.000000;1.000000;,
  87;1.000000;1.000000;1.000000;1.000000;,
  88;1.000000;1.000000;1.000000;1.000000;,
  89;1.000000;1.000000;1.000000;1.000000;,
  90;1.000000;1.000000;1.000000;1.000000;,
  91;1.000000;1.000000;1.000000;1.000000;,
  92;1.000000;1.000000;1.000000;1.000000;,
  93;1.000000;1.000000;1.000000;1.000000;,
  94;1.000000;1.000000;1.000000;1.000000;,
  95;1.000000;1.000000;1.000000;1.000000;,
  96;1.000000;1.000000;1.000000;1.000000;,
  97;1.000000;1.000000;1.000000;1.000000;,
  98;1.000000;1.000000;1.000000;1.000000;,
  99;1.000000;1.000000;1.000000;1.000000;,
  100;1.000000;1.000000;1.000000;1.000000;,
  101;1.000000;1.000000;1.000000;1.000000;,
  102;1.000000;1.000000;1.000000;1.000000;,
  103;1.000000;1.000000;1.000000;1.000000;,
  104;1.000000;1.000000;1.000000;1.000000;,
  105;1.000000;1.000000;1.000000;1.000000;,
  106;1.000000;1.000000;1.000000;1.000000;,
  107;1.000000;1.000000;1.000000;1.000000;,
  108;1.000000;1.000000;1.000000;1.000000;,
  109;1.000000;1.000000;1.000000;1.000000;,
  110;1.000000;1.000000;1.000000;1.000000;,
  111;1.000000;1.000000;1.000000;1.000000;,
  112;1.000000;1.000000;1.000000;1.000000;,
  113;1.000000;1.000000;1.000000;1.000000;,
  114;1.000000;1.000000;1.000000;1.000000;,
  115;1.000000;1.000000;1.000000;1.000000;,
  116;1.000000;1.000000;1.000000;1.000000;,
  117;1.000000;1.000000;1.000000;1.000000;,
  118;1.000000;1.000000;1.000000;1.000000;,
  119;1.000000;1.000000;1.000000;1.000000;,
  120;1.000000;1.000000;1.000000;1.000000;,
  121;1.000000;1.000000;1.000000;1.000000;,
  122;1.000000;1.000000;1.000000;1.000000;,
  123;1.000000;1.000000;1.000000;1.000000;,
  124;1.000000;1.000000;1.000000;1.000000;,
  125;1.000000;1.000000;1.000000;1.000000;,
  126;1.000000;1.000000;1.000000;1.000000;,
  127;1.000000;1.000000;1.000000;1.000000;,
  128;1.000000;1.000000;1.000000;1.000000;,
  129;1.000000;1.000000;1.000000;1.000000;;
 }
}