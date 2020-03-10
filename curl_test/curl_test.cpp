#include <iostream>
#include <curl/curl.h>
#include <string>
#include <map>

using namespace std;

//回调函数  得到响应内容
int write_data(char* buffer, size_t size, size_t nmemb, void* userp){
    std::string * str = dynamic_cast<std::string *>((std::string *)userp);
    str->append((char *)buffer, size * nmemb);
    return nmemb;
}

int posts(string url, string &body,  string* response);
int get(string url, string* response);



int main(int argc, char** argv){
	std::map<std::string, std::string> data;
	std::string body;

	std::string response;
    int status_code = get("http://www.baidu.com", &response);
	if (status_code != CURLcode::CURLE_OK) {
			return -1;
	}
	cout << response << endl;
	cout << "*********************************"  << endl;

    status_code = posts("https://www.zhihu.com", body, &response);
	if (status_code != CURLcode::CURLE_OK) {
			return -1;
	}
	cout << response << endl;

	return 0;
}

int get(string url, string* response)
{
    CURL *curl;
    CURLcode ret;
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Accept: Agent-007");
    curl = curl_easy_init();    // 初始化
    
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);        //改协议头
        curl_easy_setopt(curl, CURLOPT_URL, (char *)url.c_str());   // 指定url
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)response);
        int status_code = curl_easy_perform(curl);   // 执行


         ret = curl_easy_perform(curl);                          //执行请求
        if(ret == 0){
            curl_slist_free_all(headers);
            curl_easy_cleanup(curl);    
            return status_code;
        }
        else{
            return ret;
        }
    }
    else{
        return -1;
    }
}
//POST 处理x-www-form-urlencoded格式数据 如下
//{id: 'SEA2HHHH',
//  time: '2018-12-27T21:43:41.604Z',
//  image: 'haha' }
//则    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());           //指定post内容中
//body内容为：
//id=SEA2HHHH&image='haha&time=2019-01-02+14:22:41

int posts(string url, string &body,  string* response)
{
    CURL *curl;
    CURLcode ret;
    curl = curl_easy_init();
    long response_code = 0;
    if (curl)
    {
         curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());           //指定post内容
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, body.size());         //指定post长度
        curl_easy_setopt(curl, CURLOPT_HEADER, 0);                          //设置协议头
        // curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);             
        curl_easy_setopt(curl, CURLOPT_URL, (char *)url.c_str());           //指定url
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);          //绑定相应
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)response);        //绑定响应内容的地址
        ret = curl_easy_perform(curl);                          //执行请求
        if(ret == 0){
            curl_easy_cleanup(curl);   
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);//获取http 状态码 
            return 0;  
        }
        else{
			curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);//获取http 状态码
            return ret;
        }
    }
	else{
        return -1;
	}
}



//***************put for c(180727) 下列code未验证***************//
//put 函数用于上传数据
size_t read_data(char* buffer, size_t size, size_t nitems, void* instream){
    size_t sizes = fread(buffer, size, nitems, (FILE *)instream); 
    return nitems;
}
//put 文件, 即 raw bin 类型数据在node中接受需要使用 res.on（'data'）方式，在json编码数据可以使用req.body
int put(char* url, FILE* fd,  int fsize, char* response)//put 地址，put 文件句柄， 文件大小， 接受响应存储位置
{
    CURL *curl;
    CURLcode ret;
    curl = curl_easy_init();
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "expect: "); //将值置为空，可以屏蔽该头
    //headers = curl_slist_append(headers, "content-length: ");//put 不能省略这个头content-length
    headers = curl_slist_append(headers, "test: put");//设置put http header头
    // printf("\n%s %d\n", body, fsize);
    if (curl)
    { 
        curl_easy_setopt(curl,CURLOPT_URL, url);//配置url
        curl_easy_setopt(curl,CURLOPT_UPLOAD, 1);//设置为上传模式 PUT
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);//改协议头
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, &read_data);//配置上传内容函数处理
        curl_easy_setopt(curl, CURLOPT_READDATA, fd);//向处理函数传递 文件指针
        curl_easy_setopt(curl, CURLOPT_INFILE, fd); //定位作为上传的输入文件 
        curl_easy_setopt(curl, CURLOPT_INFILESIZE, fsize);//上传文件字节数
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);//用于接受响应回调函数
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)response);//传递接受响应内容的存储地址
        ret = curl_easy_perform(curl);                          //执行请求
        if(ret == 0){
            curl_easy_cleanup(curl);    
            return 0;  
        }
        else{
            return ret;
        }
    }
	else{
        return -1;
	}
}

//***************post(180920) 下列code未验证 普通post ****************//
int post(string url, string &body,  string* response)
{
    CURL *curl;
    curl = curl_easy_init();

    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, (char *)body.c_str());    // 指定post内容
        curl_easy_setopt(curl, CURLOPT_URL, (char *)url.c_str());   // 指定url
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
	else{
		// cout << "error" << endl;
	}

    return 0;
}

//***************(180920) 下列code未验证 post body请求参数构造****************//
void makeUrlencodedForm(map<string, string> const & params, string * content)
{
	content->clear();
	map<string, string>::const_iterator it;
	for(it=params.begin(); it!=params.end(); it++)
	{
		char * key = curl_escape(it->first.c_str(), (int) it->first.size());
		char * value = curl_escape(it->second.c_str(),(int) it->second.size());
		*content += key;
		*content += '=';
		*content += value;
		*content += '&';
		curl_free(key);
		curl_free(value);
	}
}
//***************post中 boy参数得到sample****************//
    //string body;
  	// map<string, string> data;
    // data["file"] = "file bin";
    // data["group_id"] = "deviceinfo";
	// makeUrlencodedForm(data, &body);
//************************************************************//

