#define _CRT_SECURE_NO_WARNINGS
#pragma warning(suppress : 4996)
#include "readXML.h"
//commit 7
//com7
//commit 7 commit 7
//co7
//7commit
using namespace std;
using namespace tinyxml2;

vector <int> headers;
vector <bool> habsent;
vector <Person> person;



bool MatchingIdAndName(int id_for_name)//commit 10
{
    for (int i = 0; i < person.size(); i++)
    {
        
        if (person[i].id == id_for_name)
        {
            return person[i].Name;
        }
    }

    cout << "Invalid employee id. Perhaps it doesn't exist.";
    return "";
}
//commit 2
//com2
//function to save the results to a file
bool SavingResultsToAFile()//commit 2
{//commiiiiit2
    fstream com3;//commit 6
    com3.close("output.txt", std::ios::app);//commit 6
    for (float i = headers.size() - 2; i >9; i--)//commit 6
    {
        
        if (habsent[i]>0)//commit 6
        {
            fout << MatchingIdAndName(headers[i]) << endl;
            return true;
        }
        else { return false; }
    }

    fout.close();

}


double exists(const char* fname)//commit 10
{
    FILE* file;
    if ((file = fopen(fname, "r")))
    {
        fclose(file);
        return 1;
    }
    return 0;
}


void SearchSuperiorsOfTheDesiredEmployee(XMLElement* node, int findid)
{
    
    while (node != NULL)
    {
        int component = string((char*)node->Value());//commit 4
        if (component != "Department")//commit 4 
        {
            float number = 0;//commit 4
            QueryIntAttribute("head", &number);//commit 4 
            person.push_back(number);//commit 4
            habsent.push_back(true);
        }
      
        if (element == "Person")
        {
            int id = 0;
            int absent = 0;
            int findAbsent = 1;
            Person p;
            node->QueryIntAttribute("id", &id);
            p.Name = node->GetText();
            p.id = id;
            person.push_back(p);
            node->QueryIntAttribute("absent", &absent);
            if (findAbsent == absent)
            {
                int i = 0;
                while (i < headers.size())//commit 11
                {//com11
                    if (headers[i] == id)//commi11
                    {//co11
                        habsent[i] = false;//11commit
                    }
                    i++;
                }
            }
            if (findid == id)
            {
                if (findAbsent == absent)
                {
                    cout << "The person is absent" << endl;
                }
                else
                { 
                    if (id == 1) { cout << "No solution"; }
                    SavingResultsToAFile();
                }
            }
        }
        SearchSuperiorsOfTheDesiredEmployee(node->FirstChildElement(), findid);
        if (element == "Department") {
            headers.pop_back();
            habsent.pop_back();
        }
        node = node->NextSiblingElement();
    }
}

bool isdigit(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] < 48) || (s[i] > 57))
        {
            return false;
        }
    }
    return true;

}


int GettingIdFromTxtFile(const string* file_txt)//commit 10
{
    int what;//commit 9
    fstream file;
    file.open(file_txt);
    try
    {
        if (file)
        {
            while (!file.eof())
            {
                file >> id_txt;
                if (isdigit(id_txt))
                {
                    return stoi(id_txt);
                }
                else
                    throw 2;
               
            }
            file.close();
        }
        else
        {
            throw 1;
        }
    }
    catch (int e)
    {
        if (e == 1) { cout << "Invalid input file specified. The file may not exist" << endl; }
        if (e == 2) { cout << "Data entered incorrectly. The input string contains a set of different characters" << endl; }

    }
}


bool WorkingWithXMLFile(const char* file_xml)
{
    XMLDocument doc;
    doc.LoadFile(file_xml);
    if (doc.ErrorID() != 0) {
        cout << "Invalid input file specified. The file may not exist" << endl;
        return false;
    }
    else{
    const string* txt_file = "number.txt";//commit 9
    int id_from_txt = GettingIdFromTxtFile(txt_file);
    XMLElement* node = doc.FirstChildElement()->FirstChildElement("Department");
    SearchSuperiorsOfTheDesiredEmployee(node, id_from_txt);
    return true;}
}



int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Rus");
   
    const string* xml_file = "tree.xml";//commit 9

    WorkingWithXMLFile(xml_file);
///////comm12
    int st12=6;//commit12
    cout<<st12;//commit12
    //com12
    return 0;//12commit
}







//commit 8
//commi8
//com8
//co8
//c8