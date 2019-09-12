resource "null_resource" "test_variables" {

    triggers ={
        random_number = "${timestamp()}"        # introduced to make sure that this resource will run all the time.
    }

    provisioner "local-exec" {
        command = <<EOT
        echo "stringtype value is:${var.string_type} and inttrype value is:${var.int_type}" >> c:\\temp\out.txt
    EOT
    }

    provisioner "local-exec" {
        command = <<EOT
        echo "boolean type is:${var.bool_type} " >> c:\\temp\out.txt
    EOT
    }
}

resource "null_resource" "collection_strings" {
    for_each = toset(var.collection_string_type)

   triggers ={
        random_number = "${timestamp()}"        # introduced to make sure that this resource will run all the time.
    }

    provisioner "local-exec" {
        command = <<EOT
        echo "test type is: ${each.key}" >> c:\\temp\out.txt
    EOT
    }
}

resource "null_resource" "object_type_test" {

    triggers ={
        random_number = "${timestamp()}"        # introduced to make sure that this resource will run all the time.
    }

    provisioner "local-exec" {
        command = <<EOT
        echo "object type:${var.object_type.name} ${var.object_type.age}" >> c:\\temp\out.txt
    EOT
    }
}

# resource "null_resource" "collection_objects" {
#     for_each = toset(var.collection_object_type)

#    triggers ={
#         random_number = "${timestamp()}"        # introduced to make sure that this resource will run all the time.
#     }

#     provisioner "local-exec" {
#         command = <<EOT
#         echo "test type is: ${each.key}" >> c:\\temp\out.txt
#     EOT
#     }
# }

resource "null_resource" "collection_objects" {

    count = "${length(var.collection_object_type)}"
    triggers ={
        random_number = "${timestamp()}"        # introduced to make sure that this resource will run all the time.
    }

    provisioner "local-exec" {

        command  = ".\\test.ps1 -Name  ${var.collection_object_type[count.index].name} -Age ${var.collection_object_type[count.index].age}"
        interpreter = ["PowerShell", "-Command"]
    }
}    


resource "null_resource" "map_collection_objects" {

    for_each = "${var.mapcollection_object_type}"
    triggers ={
        random_number = "${timestamp()}"        # introduced to make sure that this resource will run all the time.
    }

    provisioner "local-exec" {

        command  = ".\\test.ps1 -Name  ${each.value.name} -Age ${each.value.age}"
        interpreter = ["PowerShell", "-Command"]
    }
}