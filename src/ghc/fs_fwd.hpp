#pragma once

namespace ghc::filesystem {
    class path {
        private:
            std::string mSource;

        public:
            path(){
                mSource = "";
            }

            path(const std::string& source){
                mSource = source;
            }

            path u8path(const std::string& source) const {
                return path(source);
            }

            path operator / (const path& other) const {
                return path(mSource + "/" + other.mSource);
            }

            path operator / (const char* other) const {
                return path(mSource + "/" + other);
            }
    };
}