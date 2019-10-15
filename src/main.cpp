#include <bits/stdc++.h>

using namespace std;

string processLine(const string &line) {
    size_t firstSpacePos = line.find(' ');
    if (firstSpacePos == string::npos) {
        return line + " 0";
    }
    bool isAlpha = false;
    size_t count = 0;
    for (auto iter = line.begin() + firstSpacePos + 1; iter != line.end(); ++iter) {
        if (isalpha(*iter)) {
            if (!isAlpha) {
                isAlpha = true;
            }
        } else {
            if (isAlpha) {
                count++;
            }
            isAlpha = false;
        }
    }
    if (isAlpha) {
        count++;
    }
    return line.substr(0, firstSpacePos + 1) + to_string(count);
}

int main(int argc, char *argv[]) {
#ifdef DEBUG
    string input = "1:1 At the first God made the heaven and the earth.\n"
        "1:2 And the earth was waste and without form ; and it was dark on the face of the deep: and the Spirit of God was moving on the face of the waters.\n"
        "1:3 And God said, Let there be light: and there was light.\n"
        "1:4 And God, looking on the light, saw that it was good : and God made a division between the light and the dark,\n"
        "1:5 Naming the light, Day, and the dark, Night. And there was evening and there was morning, the first day.\n"
        "1:6 And God said, Let there be a solid arch stretching over the waters, parting the waters from the waters.\n"
        "1:7 And God made the arch for a division between the waters which were under the arch and those which were over it: and it was so.\n"
        "1:8 And God gave the arch the name of Heaven. And there was evening and there was morning, the second day.\n"
        "1:9 And God said, Let the waters under the heaven come together in one place, and let the dry land be seen: and it was so.\n"
        "1:10 And God gave the dry land the name of Earth; and the waters together in their place were named Seas: and God saw that it was good.\n"
        "1:11 And God said, Let grass come up on the earth, and plants producing seed , and fruit-trees giving fruit, in which is their seed, after their sort: and it was so.\n"
        "1:12 And grass came up on the earth, and every plant producing seed of its sort, and every tree producing fruit, in which is its seed, of its sort: and God saw that it was good.\n"
        "1:13 And there was evening and there was morning, the third day.\n"
        "1:14 And God said, Let there be lights in the arch of heaven, for a division between the day and the night, and let them be for signs, and for marking the changes of the year, and for days and for years:\n"
        "1:15 And let them be for lights in the arch of heaven to give light on the earth: and it was so.\n"
        "1:16 And God made the two great lights: the greater light to be the ruler of the day, and the smaller light to be the ruler of the night: and he made the stars.\n"
        "1:17 And God put them in the arch of heaven, to give light on the earth;\n"
        "1:18 To have rule over the day and the night, and for a division between the light and the dark: and God saw that it was good.\n"
        "1:19 And there was evening and there was morning, the fourth day.\n"
        "1:20 And God said, Let the waters be full of living things, and let birds be in flight over the earth under the arch of heaven.\n"
        "1:21 And God made great sea beasts, and every sort of living and moving thing with which the waters were full, and every sort of winged bird: and God saw that it was good.\n"
        "1:22 And God gave them his blessing, saying, Be fertile and have increase, making all the waters of the seas full, and let the birds be increased in the earth.\n"
        "1:23 And there was evening and there was morning, the fifth day.\n"
        "1:24 And God said, Let the earth give birth to all sorts of living things, cattle and all things moving on the earth, and beasts of the earth after their sort: and it was so.\n"
        "1:25 And God made the beast of the earth after its sort, and the cattle after their sort, and everything moving on the face of the earth after its sort: and God saw that it was good.\n"
        "1:26 And God said, Let us make man in our image, like us: and let him have rule over the fish of the sea and over the birds of the air and over the cattle and over all the earth and over every living thing which goes flat on the earth.\n"
        "1:27 And God made man in his image, in the image of God he made him: male and female he made them.\n"
        "1:28 And God gave them his blessing and said to them, Be fertile and have increase, and make the earth full and be masters of it; be rulers over the fish of the sea and over the birds of the air and over every living thing moving on the earth.\n"
        "1:29 And God said, See, I have given you every plant producing seed, on the face of all the earth, and every tree which has fruit producing seed: they will be for your food:\n"
        "1:30 And to every beast of the earth and to every bird of the air and every living thing moving on the face of the earth I have given every green plant for food: and it was so.\n"
        "1:31 And God saw everything which he had made and it was very good. And there was evening and there was morning, the sixth day.\n"
        "2:1 And the heaven and the earth and all things in them were complete.\n"
        "2:2 And on the seventh day God came to the end of all his work; and on the seventh day he took his rest from all the work which he had done.\n"
        "2:3 And God gave his blessing to the seventh day and made it holy: because on that day he took his rest from all the work which he had made and done.\n";
    stringstream ss(input);
    string to;
    while (getline(ss, to, '\n')) {
        cout << processLine(to) << endl;
    }
#endif
#ifndef DEBUG
    string line, to;
    while (getline(cin, to)) {
        
    }
#endif
    return 0;
}
