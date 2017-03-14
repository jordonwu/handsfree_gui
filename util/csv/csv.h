#ifndef CSV_H
#define CSV_H
#include <vector>
#include <QStringList>
#include <QFile>
#include <QRegExp>
#include <QTextStream>
#include <QDebug>
class Csv
{
public:
    static std::vector<QStringList> getCsvData(const QString &file_name, bool &is_error){
        std::vector<QStringList> error_return ;
        std::vector<QStringList> ans ;
        QFile read_file(file_name) ;
        is_error = false ;
        if(!read_file.open(QIODevice::ReadOnly)){
            read_file.close();
            return error_return ;
        }
        QTextStream out(&read_file) ;

        //use this to match csv
        QRegExp reg("^(\\w+,){3}(\\w+){1}$") ;
        QString line_string ;
        while(!out.atEnd()){
             line_string = out.readLine() ;
             if(!reg.exactMatch(line_string)){
                 read_file.close();
                 return error_return ;
             }
             ans.push_back(line_string.split(","));
             qDebug()<<line_string.split(",") ;
        }
        is_error = true ;
        read_file.close();
        return ans ;
    }
private:
    Csv(){}
    ~Csv(){}
};

#endif // CSV_H
