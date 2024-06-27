//
// Created by aleen on 3/22/2023.
//

#include "OtherMethods.h"

vector<Image::Pixel> MethodFinder(const char* argv[], int argc, Image Image1) {
    vector<Image::Pixel> finished_pixels;
    for (unsigned int i = 3; i < argc;) {
        string arg = string(argv[i]);
        if (arg == "combine") {
            if( argc >= i + 3) {
                Image GreenImage;
                fstream GImage;
                string filename = string(argv[i + 1]);
                if((filename.length() < 5) or ((filename.substr(filename.size() - 4)) != ".tga")){
                    cout << "Invalid argument, invalid file name." << endl;
                    finished_pixels.clear();
                    return finished_pixels;
                }
                GImage.open(filename, ios_base::in | ios_base::binary);
                if (not(GImage.is_open())) {
                    cout << "Invalid argument, file does not exist." << endl;
                    finished_pixels.clear();
                    return finished_pixels;
                } else {
                    GreenImage.get_data(GImage);
                    GImage.close();
                    Image BlueImage;
                    fstream BImage;
                    string filename2 = string(argv[i + 2]);
                    if((filename2.length() < 5) or ((filename2.substr(filename2.size() - 4)) != ".tga")){
                        cout << "Invalid argument, invalid file name." << endl;
                        finished_pixels.clear();
                        return finished_pixels;
                    }
                    BImage.open(filename2, ios_base::in | ios_base::binary);
                    if (not(BImage.is_open())) {
                        cout << "Invalid argument, file does not exist." << endl;
                        finished_pixels.clear();
                        return finished_pixels;
                    } else {
                        BlueImage.get_data(BImage);
                        BImage.close();
                        if (i == 3) {
                            finished_pixels = CombineBGR(BlueImage.get_pixels(), GreenImage.get_pixels(),
                                                         Image1.get_pixels());
                        } else {
                            finished_pixels = CombineBGR(BlueImage.get_pixels(), GreenImage.get_pixels(),
                                                         finished_pixels);
                        }
                        cout << "Images combined" << endl;
                        if(argc > i + 3) {
                            i = i + 3;
                        }else{
                            return finished_pixels;
                        }
                    }
                }
            }else{
                cout << "Missing argument." << endl;
                finished_pixels.clear();
                return finished_pixels;
            }
        }
        else if (arg == "screen") {
            if (argc >= i + 2) {
                Image ScreenImage;
                fstream SImage;
                string filename = string(argv[i + 1]);
                SImage.open(filename, ios_base::in | ios_base::binary);
                if (not(SImage.is_open())) {
                    cout << "Invalid argument, file does not exist." << endl;
                    finished_pixels.clear();
                    return finished_pixels;
                } else {
                    ScreenImage.get_data(SImage);
                    if (i == 3) {
                        finished_pixels = Screen(Image1.get_pixels(), ScreenImage.get_pixels());
                    } else {
                        finished_pixels = Screen(finished_pixels, ScreenImage.get_pixels());
                    }
                    cout << "Images screened." << endl;
                    if (argc > i + 2){
                        i = i + 2;
                    }else {
                        return finished_pixels;
                    }
                }
            } else {
                cout << "Missing argument." << endl;
                finished_pixels.clear();
                return finished_pixels;
            }
        }
        else if (arg == "multiply") {
            if (argc >= i + 2) {
                Image MultImage;
                fstream MImage;
                string filename = string(argv[i + 1]);
                if((filename.length() < 5) or ((filename.substr(filename.size() - 4)) != ".tga")){
                    cout << "Invalid argument, invalid file name." << endl;
                    finished_pixels.clear();
                    return finished_pixels;
                }
                MImage.open(filename, ios_base::in | ios_base::binary);
                if (not(MImage.is_open())) {
                    cout << "Invalid argument, file does not exist." << endl;
                    finished_pixels.clear();
                    return finished_pixels;
                } else {
                    MultImage.get_data(MImage);
                    if (i == 3) {
                        finished_pixels = Multiply(Image1.get_pixels(), MultImage.get_pixels());
                    } else {
                        finished_pixels = Multiply(finished_pixels, MultImage.get_pixels());
                    }
                    cout << "Images multiplied." << endl;
                    if (argc > (i + 2)) {
                        i = i + 2;
                    } else {
                        return finished_pixels;
                    }
                }
            } else{
                cout << "Missing argument." << endl;
                finished_pixels.clear();
                return finished_pixels;
            }
        }
        else if (arg == "subtract") {
            if (argc >= i + 2) {
                Image SubImage;
                fstream SImage;
                string filename = string(argv[i + 1]);
                if((filename.length() < 5) or ((filename.substr(filename.size() - 4)) != ".tga")){
                    cout << "Invalid argument, invalid file name." << endl;
                    finished_pixels.clear();
                    return finished_pixels;
                }
                SImage.open(filename, ios_base::in | ios_base::binary);
                if (not(SImage.is_open())) {
                    cout << "Invalid argument, file does not exist." << endl;
                    finished_pixels.clear();
                    return finished_pixels;
                } else {
                    SubImage.get_data(SImage);
                    if (i == 3) {
                        finished_pixels = Subtract(Image1.get_pixels(), SubImage.get_pixels());
                    } else {
                        finished_pixels = Subtract(finished_pixels, SubImage.get_pixels());
                    }
                    cout << "Images subtracted." << endl;
                    if (argc > i + 2){
                        i = i + 2;
                    } else {
                        return finished_pixels;
                    }
                }
            } else{
                cout << "Missing argument." << endl;
                finished_pixels.clear();
                return finished_pixels;
            }
        }
        else if (arg == "overlay") {
            if (argc >= i + 2) {
                Image OverImage;
                fstream OImage;
                string filename = string(argv[i + 1]);
                if((filename.length() < 5) or ((filename.substr(filename.size() - 4)) != ".tga")){
                    cout << "Invalid argument, invalid file name." << endl;
                    finished_pixels.clear();
                    return finished_pixels;
                }
                OImage.open(filename, ios_base::in | ios_base::binary);
                if (not(OImage.is_open())) {
                    cout << "Invalid argument, file does not exist." << endl;
                    finished_pixels.clear();
                    return finished_pixels;
                } else {
                    OverImage.get_data(OImage);
                    if (i == 3) {
                        finished_pixels = Overlay(Image1.get_pixels(), OverImage.get_pixels());
                    } else {
                        finished_pixels = Overlay(finished_pixels, OverImage.get_pixels());
                    }
                    cout << "Images overlayed." << endl;
                    if(argc > i + 2){
                        i = i + 2;
                    } else{
                        return finished_pixels;
                    }
                }
            } else{
                cout << "Missing argument." << endl;
                finished_pixels.clear();
                return finished_pixels;
            }
        }
        else if (arg == "addred") {
            if (argc >= i + 2) {
                try {
                    unsigned int added_red = stoi(string(argv[i + 1]));
                    if (i == 3) {
                        finished_pixels = AddRed(Image1.get_pixels(), added_red);
                    } else {
                        finished_pixels = AddRed(finished_pixels, added_red);
                    }
                    cout << "Red added to image." << endl;
                    if(argc > i + 2){
                        i = i+2;
                    } else{
                        return finished_pixels;
                    }
                }
                catch (const invalid_argument &) {
                    cout << "Invalid argument, expected number." << endl;
                    finished_pixels.clear();
                    return finished_pixels;
                }
            } else {
                cout << "Missing argument." << endl;
                finished_pixels.clear();
                return finished_pixels;
            }
        }
        else if (arg == "addgreen") {
            if (argc >= i + 2) {
                try {
                    unsigned int added_green = stoi(string(argv[i + 1]));
                    if (i == 3) {
                        finished_pixels = AddGreen(Image1.get_pixels(), added_green);
                    } else {
                        finished_pixels = AddGreen(finished_pixels, added_green);
                    }
                    cout << "Green added to image." << endl;
                    if(argc > i + 2){
                        i = i+2;
                    } else{
                        return finished_pixels;
                    }
                }
                catch (const invalid_argument &) {
                    cout << "Invalid argument, expected number." << endl;
                    finished_pixels.clear();
                    return finished_pixels;
                }
            } else {
                cout << "Missing argument." << endl;
                finished_pixels.clear();
                return finished_pixels;
            }
        }
        else if (arg == "addblue") {
            if (argc >= i + 2) {
                try {
                    unsigned int added_blue = stoi(string(argv[i + 1]));
                    if (i == 3) {
                        finished_pixels = AddBlue(Image1.get_pixels(), added_blue);
                    } else {
                        finished_pixels = AddBlue(finished_pixels, added_blue);
                    }
                    cout << "Blue added to image." << endl;
                    if(argc > i + 2){
                        i = i+2;
                    } else{
                        return finished_pixels;
                    }
                }
                catch (const invalid_argument &) {
                    cout << "Invalid argument, expected number." << endl;
                    finished_pixels.clear();
                    return finished_pixels;
                }
            } else {
                cout << "Missing argument." << endl;
                finished_pixels.clear();
                return finished_pixels;
            }
        }
        else if (arg == "scalered") {
            if (argc >= i + 2) {
                try {
                    unsigned int scalered = stoi(string(argv[i + 1]));
                    if (i == 3) {
                        finished_pixels = ScaleRed(Image1.get_pixels(), scalered);
                    } else {
                        finished_pixels = ScaleRed(finished_pixels, scalered);
                    }
                    cout << "Red scaled." << endl;
                    if(argc > i + 2){
                        i = i+2;
                    } else{
                        return finished_pixels;
                    }
                }
                catch (const invalid_argument &) {
                    cout << "Invalid argument, expected number." << endl;
                    finished_pixels.clear();
                    return finished_pixels;
                }
            } else {
                cout << "Missing argument." << endl;
                finished_pixels.clear();
                return finished_pixels;
            }
        }
        else if (arg == "scalegreen") {
            if (argc >= i + 2) {
                try {
                    unsigned int scalegreen = stoi(string(argv[i + 1]));
                    if (i == 3) {
                        finished_pixels = ScaleGreen(Image1.get_pixels(), scalegreen);
                    } else {
                        finished_pixels = ScaleGreen(finished_pixels, scalegreen);
                    }
                    cout << "Green scaled." << endl;
                    if(argc > i + 2){
                        i = i+2;
                    } else{
                        return finished_pixels;
                    }
                }
                catch (const invalid_argument &) {
                    cout << "Invalid argument, expected number." << endl;
                    finished_pixels.clear();
                    return finished_pixels;
                }
            } else {
                cout << "Missing argument." << endl;
                finished_pixels.clear();
                return finished_pixels;
            }
        }
        else if (arg == "scaleblue") {
            if (argc >= i + 2) {
                try {
                    unsigned int scaleblue = stoi(string(argv[i + 1]));
                    if (i == 3) {
                        finished_pixels = ScaleBlue(Image1.get_pixels(), scaleblue);
                    } else {
                        finished_pixels = ScaleBlue(finished_pixels, scaleblue);
                    }
                    cout << "Blue scaled." << endl;
                    if(argc > i + 2){
                        i = i+2;
                    } else{
                        return finished_pixels;
                    }
                }
                catch (const invalid_argument &) {
                    cout << "Invalid argument, expected number." << endl;
                    finished_pixels.clear();
                    return finished_pixels;
                }
            } else {
                cout << "Missing argument." << endl;
                finished_pixels.clear();
                return finished_pixels;
            }
        }
        else if (arg == "onlyred") {
            if(i == 3){
                finished_pixels = SeperateRed(Image1.get_pixels());
            }else{
                finished_pixels = SeperateRed(finished_pixels);
            }
            cout << "Red seperated from image." << endl;
            if (argc > i + 1){
                i++;
            }else {
                return finished_pixels;
            }
        }
        else if (arg == "onlygreen") {
            if(i == 3){
                finished_pixels = SeperateGreen(Image1.get_pixels());
            }else{
                finished_pixels = SeperateGreen(finished_pixels);
            }
            cout << "Green seperated from image." << endl;
            if (argc > i + 1){
                i++;
            }else {
                return finished_pixels;
            }
        }
        else if (arg == "onlyblue") {
            if(i == 3){
                finished_pixels = SeperateBlue(Image1.get_pixels());
            }else{
                finished_pixels = SeperateBlue(finished_pixels);
            }
            cout << "Blue seperated from image." << endl;
            if (argc > i + 1){
                i++;
            }else {
                return finished_pixels;
            }
        }
        else if (arg == "flip") {
            if(i == 3) {
                finished_pixels = Reverse(Image1.get_pixels());
            }else{
                finished_pixels = Reverse(finished_pixels);
            }
            cout << "Image flipped." << endl;
            if (argc > i + 1){
                i++;
            }else {
                return finished_pixels;
            }
        }
        else {
                cout << "Invalid method name." << endl;
                finished_pixels.clear();
                return finished_pixels;
            }
        }
    return finished_pixels;
}
