#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <windows.h>
#include <chrono>
#include <sstream>
using namespace std;
namespace fs = std::filesystem;


string makelower(string& input) {
	{

		string ltext = input;

		for (int i = 0; i < ltext.length(); i++)
			ltext[i] = tolower(ltext[i]);

		return ltext;
	}
}


string generateExcerpt(string& content, string& delimog, string& delim, int& varin) {
	
	string highlight;

	switch (varin) {
	case 1:
		highlight = " **" + delimog + "** ";
		break;
	case 2:
		highlight = " **" + delimog + "**.";
		break;
	case 3:
		highlight = " **" + delimog + "**,";
		break;
	case 4:
		highlight = " **" + delimog + "**!";
		break;
	case 5:
		highlight = " **" + delimog + "**?";
		break;
	case 6:
		highlight = " **" + delimog + "**;";
		break;
	case 7:
		highlight = "(**" + delimog + "**)";
		break;
	case 8:
		highlight = "(**" + delimog + "** ";
		break;
	case 9:
		highlight = " **" + delimog + "**)";
		break;
	}

	string A = content.substr(0, content.find(delim));
	string txt1;
	if (A.length() >= 250) {
		txt1 = A.substr(A.length() - 250);
	}
	else {
		txt1 = A;
	}

	string cullB = content.substr(content.find(delim) + delim.length());
	string txt2;
	if (cullB.length() >= 250) {
		txt2 = cullB.substr(0, 250);
	}
	else {
		txt2 = cullB;
	}

	string excerpt = txt1 + highlight + txt2;

	return excerpt;
}

void generate_end(const string& mainpath, int& hits, string& folder, const string& name) {
	
	string scratchfile = mainpath + "\\scratch.tmp";
	string outfile = mainpath + "\\tmpout.tmp";

	fstream scratch(scratchfile, fstream::in);
	string blah;
	getline(scratch, blah, '\0');
	scratch.close();
	
	ofstream writeout;
	writeout.open(outfile, ios_base::app);

	writeout << hits << " hit(s) in folder " << folder << ", file " << name << ":" << endl;
	writeout << "" << endl;
	writeout << blah << endl;
	writeout << "" << endl;
	writeout << "" << endl;

	writeout.close();

	char scratchc[1024];
	strcpy_s(scratchc, scratchfile.c_str());
	remove(scratchc);

	return;
}

string checkthisdelim(string& content, string& delim) {
	string precull = " " + content;
	string cull = precull.substr(precull.find(delim) - 1);
	string cull1 = cull.substr(0, cull.find(delim) + delim.length() + 1);
	return cull1;
}

bool file_exists(string& filenamewithpath) {
	if (fs::exists(filenamewithpath)) {
		return true;
	}
	else {
		return false;
	}
}

void fuckyou(const string& mainpath, string& input) {

	string scratch = mainpath + "\\scratch.tmp";

	if (file_exists(scratch) == false) {
		ofstream scratchfile;
		scratchfile.open(scratch);
		scratchfile.close();
	}

	ofstream writescratch;
	writescratch.open(scratch, ios_base::app);
	writescratch << input << endl;
	writescratch << "" << endl;
	writescratch.close();
	return;

}

int searchfile(const string& mainpath, const string& folderpath, string& searchfor, string& folder, const string& name, string& filecontent) {

	int hits = 0;
	string delim = makelower(searchfor);
	string lcontent = makelower(filecontent);

	string dA = " " + delim + " ";
	string dB = " " + delim + ".";
	string dC = " " + delim + ",";
	string dD = " " + delim + "!";
	string dE = " " + delim + "?";
	string dF = " " + delim + ";";
	string dG = "(" + delim + ")";
	string dH = "(" + delim + " ";
	string dI = " " + delim + ")";

	if (lcontent.find(delim) != string::npos) {

		string checkdelim;
		string tocull = lcontent;
	loop:
			if (tocull.find(delim) != string::npos) {
			checkdelim = checkthisdelim(tocull, delim);
			int varout = 0;
			if (checkdelim == dA) {
				varout = 1;
				string blah = generateExcerpt(tocull, delim, dA, varout);
				fuckyou(mainpath, blah);
				hits++;
				string culltmp = tocull.substr(tocull.find(dA) + dA.length());
				tocull = culltmp;
				goto loop;
			}
			if (checkdelim == dB) {
				varout = 2;
				string blah = generateExcerpt(tocull, delim, dB, varout);
				fuckyou(mainpath, blah);
				hits++;
				string culltmp = tocull.substr(tocull.find(dB) + dB.length());
				tocull = culltmp;
				goto loop;
			}
			if (checkdelim == dC) {
				varout = 3;
				string blah = generateExcerpt(tocull, delim, dC, varout);
				fuckyou(mainpath, blah);
				hits++;
				string culltmp = tocull.substr(tocull.find(dC) + dC.length());
				tocull = culltmp;
				goto loop;
			}
			if (checkdelim == dD) {
				varout = 4;
				string blah = generateExcerpt(tocull, delim, dD, varout);
				fuckyou(mainpath, blah);
				hits++;
				string culltmp = tocull.substr(tocull.find(dD) + dD.length());
				tocull = culltmp;
				goto loop;
			}
			if (checkdelim == dE) {
				varout = 5;
				string blah = generateExcerpt(tocull, delim, dE, varout);
				fuckyou(mainpath, blah);
				hits++;
				string culltmp = tocull.substr(tocull.find(dE) + dE.length());
				tocull = culltmp;
				goto loop;
			}
			if (checkdelim == dF) {
				varout = 6;
				string blah = generateExcerpt(tocull, delim, dF, varout);
				fuckyou(mainpath, blah);
				hits++;
				string culltmp = tocull.substr(tocull.find(dF) + dF.length());
				tocull = culltmp;
				goto loop;
			}
			if (checkdelim == dG) {
				varout = 7;
				string blah = generateExcerpt(tocull, delim, dG, varout);
				fuckyou(mainpath, blah);
				hits++;
				string culltmp = tocull.substr(tocull.find(dG) + dG.length());
				tocull = culltmp;
				goto loop;
			}
			if (checkdelim == dH) {
				varout = 8;
				string blah = generateExcerpt(tocull, delim, dH, varout);
				fuckyou(mainpath, blah);
				hits++;
				string culltmp = tocull.substr(tocull.find(dH) + dH.length());
				tocull = culltmp;
				goto loop;
			}
			if (checkdelim == dI) {
				varout = 9;
				string blah = generateExcerpt(tocull, delim, dI, varout);
				fuckyou(mainpath, blah);
				hits++;
				string culltmp = tocull.substr(tocull.find(dI) + dI.length());
				tocull = culltmp;
				goto loop;
			}
		}
	}
	if (hits != 0) {
		generate_end(mainpath, hits, folder, name);
	}
	cout << "searched: " << name << endl;
	cout << hits << " hit(s)" << endl;
	return hits;
}

string getfolder(const string& folderpath) {
	string folder;

	if (folderpath.find("\\") != string::npos) {
		folder = folderpath.substr(folderpath.rfind("\\") + 1, folderpath.length());
	}
	else if (folderpath.find("/") != string::npos) {
		folder = folderpath.substr(folderpath.rfind("/") + 1, folderpath.length());
	}
	else {
		cout << "ERROR getting folder information; function getfolder" << endl;
	}

	return folder;
}


int doWork(const string& mainpath, string& searchfor, const string& filepath, const string& folderpath, const string& filename, const string& name) {


	std::filesystem::current_path(folderpath); //setting path

	int hits = 0;

	string folder = getfolder(folderpath);

	if (filepath.length() >= 250)
	{

		string generatetmp = "@copy " + filename + " tmp.txt >NUL";
		int gencmd = system(generatetmp.c_str());

		fstream f("tmp.txt", fstream::in);
		string filecontent;
		getline(f, filecontent, '\0');

		f.close();

		hits = searchfile(mainpath, folderpath, searchfor, folder, name, filecontent);

		char tmpc[] = "tmp.txt";
		remove(tmpc);
	}
	else {
		fstream f(filename, fstream::in);
		string filecontent;
		getline(f, filecontent, '\0');

		f.close();

		hits = searchfile(mainpath, folderpath, searchfor, folder, name, filecontent);


	}
	return hits;
}

int checkmin(int minutes) {

	if (minutes < 15) {
		return 0;
	}
	else if (minutes > 45) {
		return 1;
	}
	else {
		return 2;
	}

}

string format_time(double milliseconds) {

	int ms = milliseconds;

	int seconds = ms / 1000;
	//ms %= 1000;

	int minutes = seconds / 60;
	seconds %= 60;

	int hours = minutes / 60;
	minutes %= 60;

	ostringstream eta;
	if ((hours < 1) && (minutes < 1) && (seconds < 1)) {
		eta << "eta: 1 second";
	}
	else if ((hours < 1) && (minutes < 1)) {
		eta << "eta: " << seconds << " second(s)";
	}
	else if (hours < 1) {
		eta << "eta: " << minutes << " minute(s)";
	}
	else if (checkmin(minutes) == 0) {
		eta << "eta: around " << hours << " hour(s)";
	}
	else if (checkmin(minutes) == 1) {
		eta << "eta: around " << hours + 1 << " hour(s)";
	}
	else if (checkmin(minutes) == 2) {
		eta << "eta: around " << hours << " and a half hour(s)";
	}

	return eta.str();

}

int gettimer(int filescomp, int totalfiles) {
	
	int filesleft = totalfiles - filescomp;

	
	if (filesleft < 1000) {
		return 30;
	}
	else if (filesleft < 5000) {
		return 100;
	}
	else if (filescomp < 59) {
		return 30;
	}
	else if (filescomp < 750) {
		return 500;
	}
	else {
		return 1000;
	}
}

void search(fs::path& p, string& mainfolder, string& mainpath, int& totalfiles) {

	int filescomp = 0;

	string searchfor;
	string outfilename;

	int inputloop = 1;
	while (inputloop == 1) {

		int err = 0;

		cout << "" << endl;
		cout << "enter search term :" << endl;
		getline(cin, searchfor);

		outfilename = "result; " + mainfolder + " - " + searchfor + ".txt";

		for (const auto& entry : fs::directory_iterator(p)) {
			const auto filepath = entry.path().string();
			const auto folderpath = entry.path().parent_path().string();
			string check = folderpath + "\\" + outfilename;
			if (filepath == check) {
				err = 1;
			}
		}
		if (err == 1) {
			cout << "" << endl;
			cout << "ERROR: search result already exists!!" << endl;
			cout << "" << endl;
		}
		else {
			inputloop = 0;
		}
	}

	ofstream tmpoutf;
	tmpoutf.open("tmpout.tmp");
	tmpoutf.close();

	int totalhits = 0;
	int counter = 0;
	auto time1 = chrono::system_clock::now();
	int timer;

	string eta = "eta: unknown";

	for (const auto& entry : fs::recursive_directory_iterator(p)) {
		const auto filepath = entry.path().string();
		const auto filename = entry.path().filename().string();
		const auto name = entry.path().stem().string();
		const auto exten = entry.path().extension().string();
		const auto folderpath = entry.path().parent_path().string();
		if (exten == ".html") {
			int newhits = doWork(mainpath, searchfor, filepath, folderpath, filename, name);
			int updatehits = totalhits + newhits;
			totalhits = updatehits;
			std::filesystem::current_path(mainpath);
			cout << totalhits << " total hits" << endl;
			filescomp++;
			cout << filescomp << "/" << totalfiles << " searched" << endl;
			timer = gettimer(filescomp, totalfiles);
			counter++;
			if (counter >= timer) {
				auto time2 = chrono::system_clock::now();
				counter = 0;
				auto duration = chrono::duration_cast<std::chrono::milliseconds>(time2 - time1).count();
				double why = duration;
				double etamil = (why / timer) * (totalfiles - filescomp);
				eta = format_time(etamil);
				time1 = chrono::system_clock::now();
			}
			cout << eta << endl;
		}
	}

	fstream f("tmpout.tmp", fstream::in);
	string blah2;
	getline(f, blah2, '\0');

	f.close();

	ofstream finalresult;
	finalresult.open(outfilename);

	finalresult << "searched " << totalfiles << " files in " << mainfolder << "." << endl;
	finalresult << "total hits: " << totalhits << endl;
	finalresult << "" << endl;
	finalresult << blah2 << endl;

	char tmpout[] = "tmpout.tmp";
	remove(tmpout);

	cout << "" << endl;
	cout << "done" << endl;
	cout << totalhits << " total hit(s)" << endl;
	cout << "" << endl;
}

void initiateSearch() {

	fs::path p = fs::current_path();
	string path = p.generic_string();

	string mainfolder = getfolder(path);

	string mainpath;

	ofstream getpath;
	getpath.open("getpath.tmp");
	char getpathc[] = "getpath.tmp";
	getpath.close();

	for (const auto& entry : fs::directory_iterator(p)) {
		const auto filepath = entry.path().parent_path().string();
		const auto filename = entry.path().filename().string();
		if (filename == "getpath.tmp") {
			mainpath = filepath;
		}
	}

	remove(getpathc);

	int totalfiles = 0;

	cout << "seaching for files" << endl;
	cout << "please wait..." << endl;

	for (const auto& entry : fs::recursive_directory_iterator(p)) {
		const auto exten = entry.path().extension().string();
		if (exten == ".html") {
			totalfiles++;
		}
	}

	cout << totalfiles << " html files found in directory" << endl;

	int mainloop = 1;
	while (mainloop == 1) {
		search(p, mainfolder, mainpath, totalfiles);
		int repeatloop = 1;
		while (repeatloop == 1) {
			cout << "search again? Y or N?" << endl;
			cout << "" << endl;
			string answer;
			getline(cin, answer);
			if ((answer == "y") || (answer == "Y")) {
				cout << "" << endl;
				repeatloop = 0;
			}
			else if ((answer == "n") || (answer == "N")) {
				mainloop = 0;
				repeatloop = 0;
			}
			else {
				cout << "" << endl;
				cout << "invalid input" << endl;
				cout << "" << endl;
			}
		}
	}

}

int main(){

	initiateSearch();

return 0;
}