<!DOCTYPE html>
<html>
    <head>
        <title>Test</title>
    </head>
    <body>
        <form method="post" enctype="multipart/form-data">
            Image file: <input type="file" name="imgfile" ></br>
	    Text file:  <input type="file" name="txtfile" ></br>
	                <input type="submit" value="Upload">
        </form>
        <?php
            if (isset($_FILES['imgfile'])) {
                $myFile = $_FILES['imgfile']; ?>
                        <p>File #1:</p>
                        <p>
                            Name: <?= $myFile["name"] ?><br>
                            Temporary file: <?= $myFile["tmp_name"] ?><br>
                            Type: <?= $myFile["type"] ?><br>
                            Size: <?= $myFile["size"] ?><br>
                            Error: <?= $myFile["error"] ?><br>
                        </p>
        <?php
            }
            if (isset($_FILES['txtfile'])) {
                $myFile = $_FILES['txtfile']; ?>
                        <p>File #2:</p>
                        <p>
                            Name: <?= $myFile["name"] ?><br>
                            Temporary file: <?= $myFile["tmp_name"] ?><br>
                            Type: <?= $myFile["type"] ?><br>
                            Size: <?= $myFile["size"] ?><br>
                            Error: <?= $myFile["error"] ?><br>
                        </p>
                    <?php
            }
        ?>
    </body>
</html>
