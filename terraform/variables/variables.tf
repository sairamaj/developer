variable "string_type" {
  description = "This is string type"
  default = "this is string"
  type = string
}

variable "int_type" {
  description = "This is int type"
  default = 99
  type = number
}

variable "bool_type" {
  description = "This is int type"
  default = true
  type = bool
}

variable "collection_string_type"{
    description = "collection string type"
    type = list(string)
    default = ["stringval1", "stringval2"]    
}

variable "object_type" {
    default = {
        name = "sai"
        age = "53"
    }
}

variable "collection_object_type"{
    description = "collection string type"
    type = list(any)
    default = [{
        name = "sai"
        age = 53
    },
    {
        name = "ram"
        age = 50
    },
    {
        name = "krishna"
        age = 49
    }]    
}

variable "mapcollection_object_type"{
    description = "collection string type"
    default = {"first":{
        name = "sai11"
        age = 53
    },
    "second":{
        name = "ram11"
        age = 50
    },
    "third":{
        name = "krishna11"
        age = 49
    }}    
}

