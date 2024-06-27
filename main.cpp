#include "OtherMethods.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


int main(int argc, const char* argv[]){
    if((argc == 1) or (string(argv[1]) == "--help" )){
        cout << "Project 2: Image Processing, Spring 2023" << endl;
        cout << endl;
        cout << "Usage:" << endl;
        cout << "\t./project2.out [output] [firstImage] [method] [...]" << endl;
        return 0;
    } else {
        if (((string(argv[1]).length() < 5)) or ((string(argv[1]).substr(string(argv[1]).size() - 4)) != ".tga")) {
            cout << "Invalid file name." << endl;
            return 0;
        }else{
            string output_file_name = string(argv[1]);
            if ((argc < 3) or ((string(argv[2]).length() < 5)) or ((string(argv[2]).substr(string(argv[2]).size() - 4)) != ".tga")) {
                cout << "Invalid file name." << endl;
                return 0;
            }else{
                Image firstImage;
                fstream image1;
                string filename = string(argv[2]);
                image1.open(filename, ios_base::in | ios_base::binary);
                if(not (image1.is_open())){
                    cout << "File does not exist." << endl;
                    return 0;
                }else{
                    firstImage.get_data(image1);
                    image1.close();
                    if(argc > 3) {
                        vector<Image::Pixel> imagepixels = MethodFinder(argv, argc, firstImage);
                        if(not(imagepixels.empty())) {
                            Image output;
                            fstream imgoutput;
                            imgoutput.open(output_file_name, ios_base::out | ios_base::binary);
                            output.create_image_file(firstImage, imagepixels, imgoutput);
                            imgoutput.close();
                            cout << "Output created." << endl;
                        }
                    }else{
                        cout << "Invalid method name." << endl;
                        return 0;
                    }
                }
            }
        }
    }
}
