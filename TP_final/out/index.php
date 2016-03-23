<!DOCTYPE html>
<html>
<head>
<style>
html {text-align:center;}
div {display:inline-block; padding:15px;}
div img {max-width:300px; max-height:200px}
</style>
</head>
<body>



<?php 
	echo "<ul>";
	$dossiers = scandir(".");
	foreach($dossiers as $dossier) {
		if (is_dir($dossier) && $dossier != "." && $dossier != "..") {
			echo "<li><a href='index.php?d=$dossier'>" . $dossier . "</a></li>";
		}
	}
	echo "</ul>";

	if (isset($_GET["d"])) {
		$dossier = $_GET["d"];
		$fichiers = scandir('./' . $dossier . '/');
	        foreach($fichiers as $fichier) {
			$info = new SplFileInfo($fichier);
        	        if ($info->getExtension() == 'jpg') {
				$src = $dossier . '/' . $fichier;
                	        echo "<div><img src='$src' /></div>";
               		}
        	}

	}

?>


</body>
</html>
